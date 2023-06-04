#include "doctest.h"
#include "sources/MagicalContainer.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("Test AscendingIterator") 
{
    MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);
    
    MagicalContainer::AscendingIterator ascIter(container);

    CHECK(ascIter == ascIter.begin());
    CHECK_EQ(*ascIter, 2);
    ++ascIter;
    CHECK_EQ(*ascIter, 3);
    ++ascIter;
    CHECK_EQ(*ascIter, 9);
    ++ascIter;
    CHECK_EQ(*ascIter, 17);
    ++ascIter;
    CHECK_EQ(*ascIter, 25);
    ++ascIter;
    CHECK(ascIter == ascIter.end());
}

TEST_CASE("Test SideCrossIterator") 
{
    MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);
    
    MagicalContainer::SideCrossIterator crossIter(container);
    
    CHECK(crossIter == crossIter.begin());
    CHECK_EQ(*crossIter, 2);
    ++crossIter;
    CHECK_EQ(*crossIter, 25);
    ++crossIter;
    CHECK_EQ(*crossIter, 3);
    ++crossIter;
    CHECK_EQ(*crossIter, 17);
    ++crossIter;
    CHECK_EQ(*crossIter, 9);
    ++crossIter;
    CHECK(crossIter == crossIter.end());
}

TEST_CASE("Test PrimeIterator") 
{
    MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);
    
    MagicalContainer::PrimeIterator primeIter(container);
    
    CHECK(primeIter == primeIter.begin());
    CHECK_EQ(*primeIter, 2);
    ++primeIter;
    CHECK_EQ(*primeIter, 3);
    ++primeIter;
    CHECK_EQ(*primeIter, 17);
    ++primeIter;
    CHECK(primeIter == primeIter.end());
}

TEST_CASE("Test container size") 
{
    MagicalContainer container;
    
    CHECK_EQ(container.size(), 0);
    
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    
    CHECK_EQ(container.size(), 3);
    
    container.removeElement(2);
    
    CHECK_EQ(container.size(), 2);
    
    container.addElement(9);
    
    CHECK_EQ(container.size(), 3);
}

TEST_CASE("Test adding and removing elements") 
{
    MagicalContainer container;
    
    // Add elements
    container.addElement(17);
    container.addElement(2);
    
    // Check size
    CHECK_EQ(container.size(), 2);
    
    CHECK_THROWS(container.removeElement(5));
    
    CHECK_NOTHROW(container.removeElement(2));
    CHECK_EQ(container.size(), 1);
    
    CHECK_NOTHROW(container.addElement(25));
    CHECK_NOTHROW(container.addElement(9));
    CHECK_NOTHROW(container.addElement(3));

    CHECK_THROWS(container.addElement(3));

    CHECK_EQ(container.size(), 4);

    CHECK_NOTHROW(container.removeElement(25));
    CHECK_NOTHROW(container.removeElement(9));

    CHECK_EQ(container.size(), 2);

    CHECK_THROWS(container.removeElement(7));

    CHECK_EQ(container.size(), 2);
}
