#include "work.hpp"
#include <stdexcept>
#include <string>

namespace work {

bool name_is_empty(std::string name) { return name.empty(); }

bool mark_is_out_of_range(unsigned mark) {
  return (mark < MIN_MARK || mark > MAX_MARK) && (mark != NO_MARK);
}

bool mark_is_not_on_first_page(unsigned mark, unsigned first_page) {
  return mark != NO_MARK && first_page != MIN_PAGE;
}

bool data_is_not_valid(std::string name, unsigned mark, unsigned page_1,
                       unsigned page_2) {
  bool invalid_name = name_is_empty(name);
  unsigned first_page{std::min<unsigned>(page_1, page_2)};
  bool invalid_mark =
      mark_is_not_on_first_page(mark, first_page) || mark_is_out_of_range(mark);

  return invalid_name || invalid_mark;
}

Work::Work(std::string name) : Work() {
  if (name_is_empty(name))
    throw std::invalid_argument("Student surname has not any data inside.");

  this->name = name;
}

Work::Work(std::string name, unsigned mark, unsigned page_1, unsigned page_2)
    : Work(name) {
  if (mark_is_out_of_range(mark))
    throw std::invalid_argument("Gotten mark is out of range.");
  unsigned first_page{std::min<unsigned>(page_1, page_2)};
  unsigned end_page{std::max<unsigned>(page_1, page_2)};
  if (mark_is_not_on_first_page(mark, first_page))
    throw std::invalid_argument("Gotten mark is not on first page.");

  this->mark = mark;
  this->first_page = first_page;
  this->end_page = end_page;
}

void Work::set_name(std::string name) {
  if (name_is_empty(name))
    throw std::invalid_argument("Student surname has not any data inside.");

  this->name = name;
}

void Work::set_mark(unsigned mark) {
  if (mark_is_out_of_range(mark))
    throw std::invalid_argument("Gotten mark is out of range.");
  if (mark_is_not_on_first_page(mark, this->first_page))
    throw std::invalid_argument("Gotten mark is not on first page.");

  this->mark = mark;
}

void Work::set_pages(unsigned page_1, unsigned page_2) {
  unsigned first_page{std::min<unsigned>(page_1, page_2)};
  unsigned end_page{std::max<unsigned>(page_1, page_2)};
  if (mark_is_not_on_first_page(this->mark, first_page))
    throw std::logic_error("Gotten mark is not on first page.");

  this->first_page = first_page;
  this->end_page = end_page;
}

Work *Work::split() const {
  if (name_is_empty(this->name))
    throw std::logic_error("Can not split work which has not surname.");

  unsigned number_of_pages = get_number_of_pages();
  Work *splited_work = new Work[number_of_pages];
  for (unsigned i = 0; i < number_of_pages; i++) {
    splited_work[i].name = this->name;
    splited_work[i].mark = NO_MARK;
    splited_work[i].first_page = i + 1;
    splited_work[i].end_page = i + 1;
  }
  splited_work[0].mark = this->mark;
  return splited_work;
}

bool Work::have_same_surname(const Work &other) const {
  if (name_is_empty(this->name))
    throw std::invalid_argument("This surname has not any data inside.");
  if (name_is_empty(other.name))
    throw std::invalid_argument("Other surname has not any data inside.");

  return this->name == other.name;
}

bool Work::have_mark_together(const Work &other) const {
  return this->mark != NO_MARK && other.mark != NO_MARK;
}

bool Work::are_consistent(const Work &other) const {
  unsigned left_end_page{std::min<unsigned>(this->end_page, other.end_page)};
  unsigned right_first_page{
      std::max<unsigned>(this->first_page, other.first_page)};
  return left_end_page + 1 == right_first_page;
}

bool Work::can_add(const Work &other) const {
  bool same_surname = have_same_surname(other);
  bool both_have_mark = have_mark_together(other);
  bool are_cons = are_consistent(other);
  return same_surname && !both_have_mark && are_cons;
}

Work Work::operator+(const Work &other) const {
  if (can_add(other) == false) {
    if (have_same_surname(other) == false)
      throw std::logic_error("Works have different surnames.");
    if (have_mark_together(other) == true)
      throw std::logic_error("Both works have mark.");
    if (are_consistent(other) == false)
      throw std::logic_error("Works are not consistent.");
  }
  Work result;

  result.name = this->name;
  result.mark = std::max<unsigned>(this->mark, other.mark);
  result.first_page = std::min<unsigned>(this->first_page, other.first_page);
  result.end_page = std::max<unsigned>(this->end_page, other.end_page);

  return result;
}

bool Work::operator==(const Work &other) const {
  if (name_is_empty(this->name))
    throw std::invalid_argument("This surname has not any data inside.");
  if (name_is_empty(other.name))
    throw std::invalid_argument("Other surname has not any data inside.");

  bool equal_surname = false;
  if (this->name == other.name)
    equal_surname = true;

  bool equal_first_page = false;
  if (this->first_page == other.first_page)
    equal_first_page = true;

  return equal_surname && equal_first_page;
}

bool Work::operator<(const Work &other) const {
  if (name_is_empty(this->name))
    throw std::invalid_argument("This surname has not any data inside.");
  if (name_is_empty(other.name))
    throw std::invalid_argument("Other surname has nit any data inside.");

  bool less_surname = false;
  if (this->name < other.name)
    less_surname = true;

  bool less_first_page = false;
  if (this->first_page < other.first_page)
    less_first_page = true;

  return less_surname || less_first_page;
}

std::ostream &operator<<(std::ostream &stream, const Work &work) {
  stream << work.name << " ";
  stream << work.mark << " ";
  stream << work.first_page << " ";
  stream << work.end_page;
  return stream;
}

std::istream &operator>>(std::istream &stream, Work &work) {
  std::string name;
  unsigned mark, page_1, page_2;
  stream >> name >> mark >> page_1 >> page_2;

  if (stream.good()) {
    if (data_is_not_valid(name, mark, page_1, page_2))
      stream.setstate(std::ios::failbit);
    else {
      work.name = name;
      work.mark = mark;
      work.first_page = std::min<unsigned>(page_1, page_2);
      work.end_page = std::max<unsigned>(page_1, page_2);
    }
  }

  return stream;
}

} // namespace work
