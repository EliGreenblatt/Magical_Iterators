#ifndef MAGICALCONTAINER_HPP
#define MAGICALCONTAINER_HPP

#include <vector>

namespace ariel
{
    class MagicalContainer
    {
        private:
            std::vector<int> elements;

        public:
            MagicalContainer();
            ~MagicalContainer();

            void addElement(int element);
            void removeElement(int element);
            int size();

        class AscendingIterator
        {
            public:
                // Constructors 
                AscendingIterator();
                AscendingIterator(MagicalContainer& container);
                ~AscendingIterator();

                // Operators
                AscendingIterator& operator++();
                AscendingIterator& operator=(const AscendingIterator& other);
                bool operator==(const AscendingIterator& other) const;
                bool operator!=(const AscendingIterator& other) const;
                bool operator>(const AscendingIterator& other) const;
                bool operator<(const AscendingIterator& other) const;
                int operator*() const;

                //Other
                AscendingIterator begin();
                AscendingIterator end();
        };

        class SideCrossIterator
        {
            public:
                // Constructors
                SideCrossIterator();
                SideCrossIterator(MagicalContainer& other);
                ~SideCrossIterator();

                // Operators
                SideCrossIterator& operator++();
                SideCrossIterator& operator=(const SideCrossIterator& other);
                bool operator==(const SideCrossIterator& other) const;
                bool operator!=(const SideCrossIterator& other) const;
                bool operator>(const SideCrossIterator& other) const;
                bool operator<(const SideCrossIterator& other) const;
                int operator*() const;
                
                // Others
                SideCrossIterator begin();
                SideCrossIterator end();
        };

        class PrimeIterator
        {
            public:
                // Constructors
                PrimeIterator();
                PrimeIterator(MagicalContainer& other);
                ~PrimeIterator();

                // Operators
                PrimeIterator& operator++();
                PrimeIterator& operator=(const PrimeIterator& other);
                bool operator==(const PrimeIterator& other) const;
                bool operator!=(const PrimeIterator& other) const;
                bool operator>(const PrimeIterator& other) const;
                bool operator<(const PrimeIterator& other) const;
                int operator*() const;
                
                // Other
                PrimeIterator begin();
                PrimeIterator end();
        };
    };
}

#endif
