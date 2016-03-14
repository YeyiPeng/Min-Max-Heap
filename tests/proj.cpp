#include "proj/proj.hpp"
#include "proj/key_val.hpp"
#include <UnitTest++/UnitTest++.h>
#include <ctime>

namespace proj
{

    TEST(Create)
    {
        mmheap<int> mmh;
    }
    
    TEST(IsEmpty)
    {
        mmheap<int> mmh;
        CHECK(mmh.isEmpty());
    }
    
    TEST(Size)
    {
        mmheap<int> mmh;
        CHECK_EQUAL(mmh.size(), 0);
        mmh.insert(5);
        CHECK_EQUAL(mmh.size(), 1);
        mmh.insert(40);
        CHECK_EQUAL(mmh.size(), 2);
        mmh.insert(50);
        CHECK_EQUAL(mmh.size(), 3);
        mmh.deleteMax();
        CHECK_EQUAL(mmh.size(), 2);
        mmh.deleteMin();
        CHECK_EQUAL(mmh.size(), 1);
        mmh.deleteMax();
        CHECK_EQUAL(mmh.size(), 0);
    }
    
    TEST(InsertAndGetMinOrMax)
    {
        mmheap<int> mmh;
        CHECK(mmh.isEmpty());
        mmh.insert(5);
        CHECK(!mmh.isEmpty());
        CHECK_EQUAL(mmh.getMin(), 5);
        mmh.insert(40);
        CHECK_EQUAL(mmh.getMax(), 40);
    }
    
    TEST(DeleteMin)
    {
        mmheap<int> mmh;
        CHECK(mmh.isEmpty());
        mmh.insert(10);
        mmh.insert(20);
        CHECK_EQUAL(mmh.getMin(), 10);
        mmh.deleteMin();
        CHECK_EQUAL(mmh.getMin(), 20);
    }
    
    TEST(DeleteMax)
    {
        mmheap<int> mmh;
        mmh.insert(5);
        mmh.insert(40);
        mmh.insert(50);
        CHECK_EQUAL(mmh.getMax(), 50);
        mmh.deleteMax();
        CHECK_EQUAL(mmh.getMax(), 40);
        mmh.deleteMax();
        CHECK_EQUAL(mmh.getMax(), 5);
        mmh.deleteMax();
        CHECK(mmh.isEmpty());
    }
    
    TEST(OneElement)
    {
        mmheap<int> mmh;
        mmh.insert(5);
        CHECK_EQUAL(mmh.getMin(), 5);
        CHECK_EQUAL(mmh.getMax(), 5);
        mmh.deleteMin();
        CHECK(mmh.isEmpty());
        
    }
    
    TEST(RandomTest_size)
    {
        mmheap<int> mmh;
        srand(time(0));
        
        CHECK_EQUAL(mmh.size(), 0);
        
        for (int i = 1; i < 101; ++i) {
            mmh.insert(rand() % 1000);
            CHECK_EQUAL(mmh.size(), i);
        }
        
    }
    
    TEST(RandomTest_insert)
    {
        mmheap<int> mmh;
        srand(time(0));
        int i = 100;
        
        while (i--) {
            mmh.insert(rand() % 1000);
            CHECK(mmh.checkInvariant());
        }
    }
    
    TEST(RandomTest_getMin_deleteMin)
    {
        mmheap<int> mmh;
        int a[100];
        srand(time(0));
        
        for (int i = 0; i < 100; ++i)
            a[i] = rand() % 1000;
        
        for (int i = 0; i < 100; ++i) {
            mmh.insert(a[i]);
            CHECK(mmh.checkInvariant());
        }
        
        std::sort(a, a + 100);
        
        CHECK_EQUAL(mmh.getMin(), a[0]);
        for (int i = 0; i < 99; ++i) {
            mmh.deleteMin();
            CHECK_EQUAL(mmh.getMin(), a[i + 1]);
        }
    }
    
    TEST(RandomTest_getMax_deleteMax)
    {
        mmheap<int> mmh;
        int a[100];
        srand(time(0));
        
        for (int i = 0; i < 100; ++i)
            a[i] = rand() % 1000;
        
        for (int i = 0; i < 100; ++i) {
            mmh.insert(a[i]);
            CHECK(mmh.checkInvariant());
        }
        
        std::sort(a, a + 100);
        
        CHECK_EQUAL(mmh.getMax(), a[99]);
        for (int i = 0; i < 99; ++i) {
            mmh.deleteMax();
            CHECK_EQUAL(mmh.getMax(), a[98 - i]);
        }
    }
    
    TEST(pairs)
    {
        typedef pair<int, std::string> isp;
        mmheap<isp> mmh;
        isp p1{1, "Monday"};
        isp p2{2, "Tuesday"};
        isp p3{3, "Wednesday"};
        isp p4{4, "Thursday"};
        isp p5{5, "Friday"};
        mmh.insert(p4);
        mmh.insert(p3);
        mmh.insert(p1);
        mmh.insert(p5);
        mmh.insert(p2);
        
        CHECK(mmh.getMin() == p1);
        CHECK(mmh.getMax() == p5);
        mmh.deleteMin();
        CHECK(mmh.getMin() == p2);
        mmh.deleteMax();
        CHECK(mmh.getMax() == p4);
        mmh.deleteMin();
        CHECK(mmh.getMin() == p3);
        mmh.deleteMax();
        CHECK(mmh.getMin() == p3);
        mmh.deleteMin();
        CHECK(mmh.isEmpty());
    }


}  // namespace proj

int main(int, const char* [])
{
    return UnitTest::RunAllTests();
}
