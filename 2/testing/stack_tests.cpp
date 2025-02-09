#define CATCH_CONFIG_MAIN

#include "../student_work/stack.hpp"
#include <catch2/catch.hpp>
using namespace stack;

TEST_CASE("StackConstructors") {
  SECTION("Default") {
    Stack s;
    REQUIRE(s.get_size() == MIN_SIZE);
    REQUIRE(s.get_top() == MIN_TOP);
  }
  SECTION("SizeOnly") {
    Stack s{10};
    REQUIRE(s.get_size() == 10);
    REQUIRE(s.get_top() == MIN_TOP);
  }
  SECTION("Full") {
    Work a{"A", 5, 1, 11};
    Work *splited_a = a.split();
    Stack s{100, 11, splited_a};
    delete[] splited_a;
    REQUIRE(s.get_size() == 100);
    REQUIRE(s.get_top() == 11);
  }
  SECTION("Copy") {
    Stack s{10};
    Stack s_copied{s};
    REQUIRE(s.get_top() == 0);
    REQUIRE(s.get_size() == 10);
    REQUIRE(s_copied.get_top() == 0);
    REQUIRE(s_copied.get_size() == 10);
  }
  SECTION("Move") {
    Stack s{10};
    Stack s_moved{std::move(s)};
    REQUIRE(s.get_top() == 0);
    REQUIRE(s.get_size() == 0);
    REQUIRE(s_moved.get_top() == 0);
    REQUIRE(s_moved.get_size() == 10);
  }
  SECTION("Exceptions") {
    Work a{"A", 4, 1, 22};
    Work *splited_a = a.split();
    REQUIRE_THROWS(Stack{1, 10, splited_a});
    delete[] splited_a;
    splited_a = nullptr;
    REQUIRE_THROWS(Stack{10, 1, splited_a});
  }
}

TEST_CASE("OverloadOfAssigmentCopy") {
  Stack s{10};
  Stack s_copied = s;
  REQUIRE(s.get_top() == 0);
  REQUIRE(s.get_size() == 10);
  REQUIRE(s_copied.get_top() == 0);
  REQUIRE(s_copied.get_size() == 10);
}

TEST_CASE("OverloadOfAssigmentMove") {
  Stack s{10};
  Stack s_moved = std::move(s);
  REQUIRE(s.get_size() == 0);
  REQUIRE(s.get_top() == 0);
  REQUIRE(s_moved.get_size() == 10);
  REQUIRE(s_moved.get_top() == 0);
}

TEST_CASE("OvedloadOfAdditionAssigment") {
  Stack s{3};
  Work a0{"A", 5, 1, 2};
  Work a1{"A", 5, 1, 2};
  Work a2{"A", 5, 1, 2};
  Work a3{"A", 5, 1, 2};
  s += a0;
  REQUIRE(s.get_top() == 1);
  s += a1;
  REQUIRE(s.get_top() == 2);
  s += a2;
  REQUIRE(s.get_top() == 3);
  REQUIRE_THROWS(s += a3);
}

TEST_CASE("Pop") {
  SECTION("Pop") {
    Stack s{10};
    Work a0{"A", 5, 1, 2};
    Work a1{"A", 4, 1, 2};
    s += a0;
    s += a1;
    Work poped = s.pop();
    REQUIRE(poped.get_name() == "A");
    REQUIRE(poped.get_mark() == 4);
    REQUIRE(poped.get_first_page() == 1);
    REQUIRE(poped.get_end_page() == 2);
    REQUIRE(s.get_top() == 1);
  }
  SECTION("PopWithoutMark") {
    Stack s{10};
    Work a0{"AA", 0, 4, 5};
    Work a1{"A", 5, 1, 2};
    Work a2{"A", 5, 1, 2};
    s += a0;
    s += a1;
    s += a2;
    Work poped = s.pop_without_mark();
    REQUIRE(poped.get_name() == "AA");
    REQUIRE(poped.get_mark() == NO_MARK);
    REQUIRE(poped.get_first_page() == 4);
    REQUIRE(poped.get_end_page() == 5);
    REQUIRE(s.get_top() == 2);
  }
  SECTION("Exceptions") {
    Stack s{10};
    REQUIRE_THROWS(s.pop());
    REQUIRE_THROWS(s.pop_without_mark());
  }
}

TEST_CASE("SummAll") {
  SECTION("Work") {
    Work a{"A", 5, 1, 10};
    Work *splited_a = a.split();
    Stack s{100, 10, splited_a};
    delete[] splited_a;
    s.summ_all();
    Work poped = s.pop();
    REQUIRE(poped.get_name() == "A");
    REQUIRE(poped.get_mark() == 5);
    REQUIRE(poped.get_first_page() == 1);
    REQUIRE(poped.get_end_page() == 10);
  }
  SECTION("Exception") {
    Stack s{10};
    REQUIRE_THROWS(s.summ_all());
  }
}

TEST_CASE("SplitAll") {
  SECTION("Work") {
    Work a{"A", 5, 1, 10};
    Stack s{100};
    s += a;
    s.split_all();
    REQUIRE(s.get_top() == 10);
  }
  SECTION("Exception") {
    Stack s{10};
    REQUIRE_THROWS(s.summ_all());
  }
}
