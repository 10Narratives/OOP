#define CATCH_CONFIG_MAIN

#include "../student_work/work.hpp"
#include <catch2/catch.hpp>

using namespace work;

TEST_CASE("WorkConstructor") {
  SECTION("Default") {
    Work a;
    REQUIRE(a.get_name() == "");
    REQUIRE(a.get_mark() == NO_MARK);
    REQUIRE(a.get_first_page() == MIN_PAGE);
    REQUIRE(a.get_end_page() == MIN_PAGE);
  }
  SECTION("NameOnly") {
    Work a{"A"};
    REQUIRE(a.get_name() == "A");
    REQUIRE(a.get_mark() == NO_MARK);
    REQUIRE(a.get_first_page() == MIN_PAGE);
    REQUIRE(a.get_end_page() == MIN_PAGE);
  }
  SECTION("Full") {
    Work a{"A", 5, 1, 10};
    REQUIRE(a.get_name() == "A");
    REQUIRE(a.get_mark() == 5);
    REQUIRE(a.get_first_page() == 1);
    REQUIRE(a.get_end_page() == 10);
    Work b{"B", 5, 10, 1};
    REQUIRE(b.get_name() == "B");
    REQUIRE(b.get_mark() == 5);
    REQUIRE(b.get_first_page() == 1);
    REQUIRE(b.get_end_page() == 10);
  }
  SECTION("Exceptions") {
    REQUIRE_THROWS(Work{""});
    REQUIRE_THROWS(Work{"", 5, 1, 10});
    REQUIRE_THROWS(Work{"A", 10, 1, 10});
    REQUIRE_THROWS(Work{"A", 5, 2, 10});
  }
}

TEST_CASE("Setters") {
  SECTION("SetName") {
    Work a;
    a.set_name("A");
    REQUIRE(a.get_name() == "A");
  }
  SECTION("SetNameException") {
    Work a;
    REQUIRE_THROWS(a.set_name(""));
  }
  SECTION("SetMark") {
    Work a;
    a.set_mark(5);
    REQUIRE(a.get_mark() == 5);
  }
  SECTION("SetMarkExceptions") {
    Work a;
    REQUIRE_THROWS(a.set_mark(100));
    a.set_pages(5, 5);
    REQUIRE_THROWS(a.set_mark(5));
  }
  SECTION("SetPages") {
    Work a;
    a.set_pages(1, 10);
    REQUIRE(a.get_first_page() == 1);
    REQUIRE(a.get_end_page() == 10);
    Work b;
    b.set_pages(10, 1);
    REQUIRE(b.get_first_page() == 1);
    REQUIRE(b.get_end_page() == 10);
  }
  SECTION("SetPagesException") {
    Work a;
    a.set_mark(5);
    REQUIRE_THROWS(a.set_pages(2, 10));
  }
}

TEST_CASE("Split") {
  SECTION("SplitWork") {
    Work a{"A", 5, 1, 10};
    Work *splited_a = a.split();
    for (unsigned i = 0; i < a.get_number_of_pages(); i++) {
      REQUIRE(splited_a[i].get_name() == "A");
      REQUIRE(splited_a[i].get_first_page() == i + 1);
      REQUIRE(splited_a[i].get_end_page() == i + 1);
      if (i > 0)
        REQUIRE(splited_a[i].get_mark() == NO_MARK);
    }
    REQUIRE(splited_a[0].get_mark() == 5);
  }
  SECTION("SplitException") {
    Work a;
    REQUIRE_THROWS(a.split());
  }
}

TEST_CASE("OverloadOfAddition") {
  SECTION("OverloadWork") {
    Work a0{"A", 5, 1, 2};
    Work a1{"A", 0, 3, 4};
    Work a01 = a0 + a1;
    Work a10 = a1 + a0;
    REQUIRE(a01.get_name() == "A");
    REQUIRE(a01.get_mark() == 5);
    REQUIRE(a01.get_first_page() == 1);
    REQUIRE(a01.get_end_page() == 4);
    REQUIRE(a10.get_name() == "A");
    REQUIRE(a10.get_mark() == 5);
    REQUIRE(a10.get_first_page() == 1);
    REQUIRE(a10.get_end_page() == 4);
  }
  SECTION("OverloadExceptions") {
    Work a0{"A", 5, 1, 2};
    Work a1{"A", 5, 1, 5};
    Work a2{"A", 0, 10, 12};
    Work b0{"B", 0, 3, 4};
    REQUIRE_THROWS(a0 + a1);
    REQUIRE_THROWS(a0 + a2);
    REQUIRE_THROWS(a0 + b0);
  }
}

TEST_CASE("OverloadOfEqulity") {
  SECTION("OverloadWork") {
    Work a0{"A", 5, 1, 2};
    Work a1{"A", 5, 1, 4};
    Work a3{"A", 0, 3, 4};
    Work b0{"B", 0, 3, 2};
    Work b1{"B", 0, 3, 4};
    REQUIRE((a0 == a1) == true);
    REQUIRE((a0 == b0) == false);
    REQUIRE((a0 == a3) == false);
  }
  SECTION("OverloadExceptions") {
    Work a, b{"B"};
    REQUIRE_THROWS(a == b);
    REQUIRE_THROWS(b == a);
  }
}

TEST_CASE("OverloadOfLess") {
  SECTION("OverloadWork") {
    Work a0{"A", 5, 1, 2};
    Work a1{"A", 0, 3, 4};
    Work b0{"B", 5, 1, 2};
    Work b1{"B", 0, 3, 4};
    REQUIRE((a0 < a1) == true);
    REQUIRE((a0 < b0) == true);
    REQUIRE((b0 < b1) == true);
  }
  SECTION("OverloadExceptions") {
    Work a, b{"B"};
    REQUIRE_THROWS(a < b);
    REQUIRE_THROWS(b < a);
  }
}
