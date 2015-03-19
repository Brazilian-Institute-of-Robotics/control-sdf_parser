#include <boost/test/unit_test.hpp>
#include <sdf_parser/Dummy.hpp>

using namespace sdf_parser;

BOOST_AUTO_TEST_CASE(it_should_not_crash_when_welcome_is_called)
{
    sdf_parser::DummyClass dummy;
    dummy.welcome();
}
