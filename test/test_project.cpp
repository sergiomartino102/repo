#define BOOST_TEST_MODULE movie_booking_tests

#include <boost/test/unit_test.hpp>
#include "service/LinkedinManagerImpl.hpp"
#include "TestUtils.hpp"

BOOST_AUTO_TEST_SUITE(tests_suite)

BOOST_AUTO_TEST_CASE(testInvalidAddMember)
{
  LinkedinManager* linkedinManager = new LinkedinManagerImpl();
  Member member = Member();
  BOOST_CHECK_EQUAL(false, linkedinManager->addMember(member));
  Member member1 = TestUtils::generateMember("Vipul Rathore");
  BOOST_CHECK_EQUAL(true, linkedinManager->addMember(member1));
  BOOST_CHECK_EQUAL(false, linkedinManager->addMember(member1));
}

BOOST_AUTO_TEST_CASE(testSuccessAddMember)
{
  LinkedinManager* linkedinManager = new LinkedinManagerImpl();
  Member member1 = TestUtils::generateMember("Vipul Rathore");
  BOOST_CHECK_EQUAL(true, linkedinManager->addMember(member1));
  BOOST_CHECK_EQUAL(false, linkedinManager->addMember(member1));
  Member member2 = TestUtils::generateMember("Vivek Kundariya");
  BOOST_CHECK_EQUAL(true, linkedinManager->addMember(member2));
  BOOST_CHECK_EQUAL(false, linkedinManager->addMember(member2));
}

BOOST_AUTO_TEST_CASE(testAddConnectionWithMemberExistButConnectionNotExist)
{
  LinkedinManager* linkedinManager = new LinkedinManagerImpl();
  Member member1 = TestUtils::generateMember("Vivek Kundariya");
  BOOST_CHECK_EQUAL(true, linkedinManager->addMember(member1));
  BOOST_CHECK_EQUAL(false, linkedinManager->addConnection(member1.getId(), TestUtils::random_string(10)));
  BOOST_CHECK_EQUAL(false, linkedinManager->addConnection(member1.getId(), member1.getId()));
}

BOOST_AUTO_TEST_CASE(testAddConnectionWithConnectionExistButMemberNotExist)
{
  LinkedinManager* linkedinManager = new LinkedinManagerImpl();
  Member member1 = TestUtils::generateMember("Vipul Rathore");
  BOOST_CHECK_EQUAL(true, linkedinManager->addMember(member1));
  BOOST_CHECK_EQUAL(false, linkedinManager->addConnection(TestUtils::random_string(10), member1.getId()));
  BOOST_CHECK_EQUAL(false, linkedinManager->addConnection(member1.getId(), member1.getId()));
}

BOOST_AUTO_TEST_CASE(testAddConnectionWithConnectionExistMemberExist)
{
  LinkedinManager* linkedinManager = new LinkedinManagerImpl();
  BOOST_CHECK_EQUAL(false, linkedinManager->addConnection(TestUtils::random_string(10), TestUtils::random_string(10)));

  Member member1 = TestUtils::generateMember("Vipul Rathore");
  BOOST_CHECK_EQUAL(true, linkedinManager->addMember(member1));

  Member member2 = TestUtils::generateMember("Vivek Kundariya");
  BOOST_CHECK_EQUAL(true, linkedinManager->addMember(member2));

  BOOST_CHECK_EQUAL(true, linkedinManager->addConnection(member1.getId(), member2.getId()));
  BOOST_CHECK_EQUAL(false, linkedinManager->addConnection(member1.getId(), member2.getId()));
  BOOST_CHECK_EQUAL(false, linkedinManager->addConnection(member2.getId(), member1.getId()));
}

BOOST_AUTO_TEST_CASE(testNonExistConnectionDegree)
{
  LinkedinManager* linkedinManager = new LinkedinManagerImpl();
  BOOST_CHECK_EQUAL(-1, linkedinManager->getConnectionDegree(TestUtils::random_string(10), TestUtils::random_string(10)));

  Member member1 = TestUtils::generateMember("Vipul Rathore");
  BOOST_CHECK_EQUAL(true, linkedinManager->addMember(member1));
  BOOST_CHECK_EQUAL(-1, linkedinManager->getConnectionDegree(member1.getId(), TestUtils::random_string(10)));
  BOOST_CHECK_EQUAL(-1, linkedinManager->getConnectionDegree(member1.getId(), member1.getId()));

  Member member2 = TestUtils::generateMember("Vivek Kundariya");
  BOOST_CHECK_EQUAL(true, linkedinManager->addMember(member2));
  BOOST_CHECK_EQUAL(-1, linkedinManager->getConnectionDegree(TestUtils::random_string(10), member2.getId()));
  BOOST_CHECK_EQUAL(-1, linkedinManager->getConnectionDegree(member2.getId(), member2.getId()));
}

BOOST_AUTO_TEST_CASE(testConnectionDegree1)
{
  LinkedinManager* linkedinManager = new LinkedinManagerImpl();
  BOOST_CHECK_EQUAL(-1, linkedinManager->getConnectionDegree(TestUtils::random_string(10), TestUtils::random_string(10)));

  Member member1 = TestUtils::generateMember("Vipul Rathore");
  BOOST_CHECK_EQUAL(true, linkedinManager->addMember(member1));

  Member member2 = TestUtils::generateMember("Vivek Kundariya");
  BOOST_CHECK_EQUAL(true, linkedinManager->addMember(member2));

  BOOST_CHECK_EQUAL(true, linkedinManager->addConnection(member1.getId(), member2.getId()));
  BOOST_CHECK_EQUAL(1, linkedinManager->getConnectionDegree(member1.getId(), member2.getId()));
  BOOST_CHECK_EQUAL(1, linkedinManager->getConnectionDegree(member2.getId(), member1.getId()));
}

BOOST_AUTO_TEST_CASE(testConnectionDegree2)
{
  LinkedinManager* linkedinManager = new LinkedinManagerImpl();
  BOOST_CHECK_EQUAL(-1, linkedinManager->getConnectionDegree(TestUtils::random_string(10), TestUtils::random_string(10)));

  Member member1 = TestUtils::generateMember("Vipul Rathore");
  BOOST_CHECK_EQUAL(true, linkedinManager->addMember(member1));

  Member member2 = TestUtils::generateMember("Vivek Kundariya");
  BOOST_CHECK_EQUAL(true, linkedinManager->addMember(member2));

  Member member3 = TestUtils::generateMember("Gunjit Agarwal");
  BOOST_CHECK_EQUAL(true, linkedinManager->addMember(member3));

  BOOST_CHECK_EQUAL(true, linkedinManager->addConnection(member1.getId(), member2.getId()));
  BOOST_CHECK_EQUAL(true, linkedinManager->addConnection(member2.getId(), member3.getId()));

  BOOST_CHECK_EQUAL(1, linkedinManager->getConnectionDegree(member1.getId(), member2.getId()));
  BOOST_CHECK_EQUAL(1, linkedinManager->getConnectionDegree(member2.getId(), member3.getId()));
  BOOST_CHECK_EQUAL(2, linkedinManager->getConnectionDegree(member1.getId(), member3.getId()));
}

BOOST_AUTO_TEST_CASE(testConnectionDegree3plus)
{
  LinkedinManager* linkedinManager = new LinkedinManagerImpl();
  BOOST_CHECK_EQUAL(-1, linkedinManager->getConnectionDegree(TestUtils::random_string(10), TestUtils::random_string(10)));

  Member member1 = TestUtils::generateMember("Vipul Rathore");
  BOOST_CHECK_EQUAL(true, linkedinManager->addMember(member1));

  Member member2 = TestUtils::generateMember("Vivek Kundariya");
  BOOST_CHECK_EQUAL(true, linkedinManager->addMember(member2));

  Member member3 = TestUtils::generateMember("Gunjit Agarwal");
  BOOST_CHECK_EQUAL(true, linkedinManager->addMember(member3));

  Member member4 = TestUtils::generateMember("Srini");
  BOOST_CHECK_EQUAL(true, linkedinManager->addMember(member4));

  BOOST_CHECK_EQUAL(true, linkedinManager->addConnection(member1.getId(), member2.getId()));
  BOOST_CHECK_EQUAL(true, linkedinManager->addConnection(member2.getId(), member3.getId()));
  BOOST_CHECK_EQUAL(true, linkedinManager->addConnection(member3.getId(), member4.getId()));

  BOOST_CHECK_EQUAL(1, linkedinManager->getConnectionDegree(member1.getId(), member2.getId()));
  BOOST_CHECK_EQUAL(1, linkedinManager->getConnectionDegree(member2.getId(), member3.getId()));
  BOOST_CHECK_EQUAL(2, linkedinManager->getConnectionDegree(member1.getId(), member3.getId()));
  BOOST_CHECK_EQUAL(2, linkedinManager->getConnectionDegree(member2.getId(), member4.getId()));
  BOOST_CHECK_EQUAL(3, linkedinManager->getConnectionDegree(member1.getId(), member4.getId()));
  BOOST_CHECK_EQUAL(3, linkedinManager->getConnectionDegree(member4.getId(), member1.getId()));

  Member member5 = TestUtils::generateMember("Kany");
  BOOST_CHECK_EQUAL(true, linkedinManager->addMember(member5));
  BOOST_CHECK_EQUAL(3, linkedinManager->getConnectionDegree(member5.getId(), member1.getId()));
  BOOST_CHECK_EQUAL(3, linkedinManager->getConnectionDegree(member1.getId(), member5.getId()));

  Member member6 = TestUtils::generateMember("Chetan");
  BOOST_CHECK_EQUAL(true, linkedinManager->addMember(member6));
  BOOST_CHECK_EQUAL(3, linkedinManager->getConnectionDegree(member5.getId(), member6.getId()));

  BOOST_CHECK_EQUAL(true, linkedinManager->addConnection(member4.getId(), member5.getId()));
  BOOST_CHECK_EQUAL(3, linkedinManager->getConnectionDegree(member5.getId(), member1.getId()));
  BOOST_CHECK_EQUAL(3, linkedinManager->getConnectionDegree(member1.getId(), member5.getId()));
}

BOOST_AUTO_TEST_SUITE_END()