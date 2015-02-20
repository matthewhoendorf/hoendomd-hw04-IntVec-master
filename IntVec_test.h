#include "IntVec.h"
#include <stdexcept>

#include <cxxtest/TestSuite.h>

class IntVecTest : public CxxTest::TestSuite {
public:

  /* -------------------- Default Constructor Tests -------------------- */

  void testDefaultConstructor0() {
    IntVec a;
    TS_ASSERT_EQUALS(0, a.size());
  }

  void testDefaultConstructor1() {
    IntVec a;
    a.push_back(5);
    a.push_back(1);
    a.push_back(3);
    TS_ASSERT_EQUALS(3, a.size());
  }
  
  void testDefaultConstructor2() {
    IntVec a;
    a.push_back(5);
    a.push_back(1);
    a.push_back(3);
    TS_ASSERT_EQUALS(4, a.capacity());
  }
  
  void testDefaultConstructor3() {
    IntVec a;
    a.push_back(5);
    a.push_back(1);
    a.push_back(3);
    TS_ASSERT_EQUALS(3, a.getAt(2));
  }
  
  void testDefaultConstructor4() {
    IntVec a;
    a.push_back(5);
    a.push_back(1);
    a.push_back(3);
    a.setAt(3,1);
    TS_ASSERT_EQUALS(3, a.getAt(1));
  }
  
  void testDefaultConstructor5() {
    IntVec a;
    a.push_back(5);
    a.push_back(1);
    a.push_back(3);
    a.push_back(5);
    a.push_back(1);
    a.push_back(3);
    a.push_back(5);
    a.push_back(1);
    a.push_back(3);
    TS_ASSERT_EQUALS(16, a.capacity());
  }
  
  /* -------------------- Copy Constructor Tests -------------------- */
  
  void testCopyConstructor0() {
    IntVec a;
    a.push_back(5);
    a.push_back(1);
    a.push_back(3);
    IntVec b(a);
    TS_ASSERT_EQUALS(3, b.size());
  } 
  
  void testCopyConstructor1() {
    IntVec a;
    a.push_back(5);
    a.push_back(1);
    a.push_back(3);
    a.push_back(5);
    a.push_back(1);
    a.push_back(3);
    a.push_back(5);
    a.push_back(1);
    a.push_back(3);
    IntVec b(a);
    TS_ASSERT_EQUALS(16, b.capacity());
  }
  
  void testCopyConstructor2() {
    IntVec a;
    a.push_back(5);
    a.push_back(1);
    a.push_back(3);
    IntVec b(a);
    TS_ASSERT_EQUALS(3, b.getAt(2));
  } 
  
  void testCopyConstructor3() {
    IntVec a;
    a.push_back(5);
    a.push_back(1);
    a.push_back(3);
    IntVec b(a);
    b.setAt(3,1);
    TS_ASSERT_EQUALS(3, b.getAt(1));
  }
  
  void testCopyConstructor4() {
    IntVec a;
    a.push_back(5);
    IntVec b(a);
    b.push_back(6);
    TS_ASSERT_EQUALS(2, b.size());
  }  
  
  void testCopyConstructor5() {
    IntVec a;
    a.push_back(5);
    IntVec b(a);
    b.push_back(6);
    TS_ASSERT_EQUALS(1, a.size());
  }  
  
  /* -------------------- String Constructor Tests -------------------- */
  
  void testDefaultConstructorString0() {
    IntVec a("[0, 1]");
    TS_ASSERT_EQUALS(2, a.size());
  }
  
  void testDefaultConstructorString1() {
    IntVec a("[0, 1, 2]");
    TS_ASSERT_EQUALS(4, a.capacity());
  }
  
  void testDefaultConstructorString2() {
    IntVec a("[0, 1]");
    TS_ASSERT_EQUALS(1, a.getAt(1));
  }
  
  void testDefaultConstructorString3() {
    IntVec a("[0, 1]");
    a.setAt(2,1);
    TS_ASSERT_EQUALS(2, a.getAt(1));
  }
  
  void testDefaultConstructorString4() {
    IntVec a("[0, a, b, c, 2]");
    TS_ASSERT_EQUALS(5, a.size());
  }
  
  void testDefaultConstructorString5() {
    IntVec a("[0, a, b, c, 2]");
    a.push_back(2);
    TS_ASSERT_EQUALS(2, a.getAt(5));
  }
  
  void testDefaultConstructorString6() {
    IntVec a("[0, a, b, c, 2]");
    TS_ASSERT_EQUALS(0, a.getAt(2));
  }
  
  void testDefaultConstructorString7() {
    IntVec a("[0, a, b, c, defg -2]");
    TS_ASSERT_EQUALS(7, a.size());
  }
  
  void testDefaultConstructorString8() {
    IntVec a("[0, P, 123, 4]");
    TS_ASSERT_EQUALS(0, a.getAt(1));
  }
  
  void testDefaultConstructorString9() {
    IntVec a("[0, P, 123, 4]");
    TS_ASSERT_EQUALS(123, a.getAt(2));
  }
  
  /* -------------------- Function Tests -------------------- */
  
  void testClear0() {
    IntVec a("[1,2,3,4]");
    a.clear();
    TS_ASSERT_EQUALS(0, a.size());
  }
  
  void testSum0() {
    IntVec a;
    a.push_back(5);
    a.push_back(1);
    a.push_back(3);
    TS_ASSERT_EQUALS(9, a.sum());
  }
  
  void testSum1() {
    IntVec a("[5,1,3]");
    TS_ASSERT_EQUALS(9, a.sum());
  }
  
  void testSum2() {
    IntVec a;
    TS_ASSERT_EQUALS(0, a.sum());
  }
  
  void testAverage0() {
    IntVec a;
    a.push_back(5);
    a.push_back(1);
    a.push_back(3);
    TS_ASSERT_EQUALS(3, a.average());
  }
  
  void testAverage1() {
    IntVec a("[5,1,3]");
    TS_ASSERT_EQUALS(3, a.average());
  }
  
  void testAverage2() {
    IntVec a;
    TS_ASSERT_EQUALS(0, a.average());
  }
  
  void testStandardDev0() {
    IntVec a;
    a.push_back(1);
    a.push_back(1);
    a.push_back(1);
    TS_ASSERT_EQUALS(0, a.standardDev());
  }
  
  void testStandardDev1() {
    IntVec a("[2,4]");
    TS_ASSERT_EQUALS(1, a.standardDev());
  }
  
  void testStandardDev2() {
    IntVec a;
    TS_ASSERT_EQUALS(0, a.standardDev());
  }
  
  void testStandardDev3() {
    IntVec a("[1]");
    TS_ASSERT_EQUALS(0, a.standardDev());
  }
  
  void testAddVec0() {
    IntVec a;
    a.push_back(5);
    a.push_back(1);
    a.push_back(3);
    IntVec b("[1,1,1]");
    IntVec c = a.add(b);
    TS_ASSERT_EQUALS(12, c.sum());
  }
  
  void testAddVec1() {
    IntVec a;
    a.push_back(5);
    a.push_back(1);
    a.push_back(3);
    IntVec b("[5,1]");
    IntVec c = a.add(b);
    TS_ASSERT_EQUALS(0, c.size());
  }
  
  void testAddVec2() {
    IntVec a("[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20]");
    IntVec b("[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20]");
    IntVec c = a.add(b);
    TS_ASSERT_EQUALS(420, c.sum());
  }
  
  void testAddNum0() {
   IntVec a("[5,1,3]");
    IntVec c = a.add(5);
    TS_ASSERT_EQUALS(24, c.sum());
  }
  
  void testAddNum1() {
    IntVec a("[5,1,3]");
    IntVec c = a.add(5);
    TS_ASSERT_EQUALS(10, c.getAt(0));
  }
  
  void testAddNum2() {
    IntVec a("[5,1,3]");
    IntVec c = a.add(10);
    c.push_back(a.getAt(0));
    TS_ASSERT_EQUALS(5, c.getAt(3));
  }
  
  void testgetAsString0() {
    IntVec a("[5,1,3]");
    TS_ASSERT_EQUALS("[5, 1, 3]", a.getAsString());
  }
  
  void testgetAsString1() {
    IntVec a;
    a.push_back(5);
    a.push_back(1);
    a.push_back(3);
    TS_ASSERT_EQUALS("[5, 1, 3]", a.getAsString());
  }
  
  void testgetAsString2() {
    IntVec a;
    a.push_back(5);
    a.push_back(1);
    a.push_back(3);
    IntVec b("[1,1,1]");
    IntVec c = a.add(b);
    TS_ASSERT_EQUALS("[6, 2, 4]", c.getAsString());
  }
  
  void testgetAsString3() {
    IntVec a;
    a.push_back(5);
    a.push_back(1);
    a.push_back(3);
    IntVec b("[1,1,1]");
    IntVec c = a.add(b);
    IntVec d = c.append(c).append(b).append(a);
    TS_ASSERT_EQUALS("[6, 2, 4, 6, 2, 4, 1, 1, 1, 5, 1, 3]", d.getAsString());
  }
  
  void testgetAsString4() {
    IntVec a;
    a.push_back(513);
    TS_ASSERT_EQUALS("[513]", a.getAsString());
  }
  
  void testgetAsString5() {
    IntVec a;
    TS_ASSERT_EQUALS("[]", a.getAsString());
  }
  
  void testEquals0() {
    IntVec a;
    a.push_back(5);
    a.push_back(1);
    a.push_back(3);
    IntVec b("[5,1,3]");
    TS_ASSERT_EQUALS(1, a.equals(b));
  }
  
  void testEquals1() {
    IntVec a;
    a.push_back(5);
    a.push_back(1);
    a.push_back(3);
    IntVec b("[5,1,3,4]");
    TS_ASSERT_EQUALS(0, a.equals(b));
  }
  
  void testEquals2() {
    IntVec a;
    a.push_back(5);
    a.push_back(1);
    a.push_back(3);
    IntVec b("[5,1,1]");
    TS_ASSERT_EQUALS(0, a.equals(b));
  }
  
  void testAppend0() {
    IntVec a("[1, 2, 3]");
    IntVec b;
    b.push_back(4);
    b.push_back(5);
    b.push_back(6);
    IntVec c = a.append(b);
    
    TS_ASSERT_EQUALS("[1, 2, 3, 4, 5, 6]" , c.getAsString());
  }
  
  void testAppend1() {
    IntVec a("[1, 2, 3]");
    IntVec b;
    b.push_back(4);
    b.push_back(5);
    b.push_back(6);
    IntVec c = a.append(b).append(b);
    
    TS_ASSERT_EQUALS("[1, 2, 3, 4, 5, 6, 4, 5, 6]" , c.getAsString());
  }
  
  void testAppend2() {
    IntVec a("[1, 2, 3]");
    IntVec b;
    IntVec c = a.append(b);
    
    TS_ASSERT_EQUALS("[1, 2, 3]" , c.getAsString());
  }
  
  void testAppend3() {
    IntVec a("[1, 2, 3]");
    IntVec b;
    b.push_back(41);
    b.push_back(52);
    b.push_back(63);
    IntVec c = a.append(b);
    
    TS_ASSERT_EQUALS("[1, 2, 3, 41, 52, 63]" , c.getAsString());
  }

};
