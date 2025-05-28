#pragma once
#include <cstddef>
#include <vector>

class  Jacobsthal
{
	public:

		Jacobsthal();
		~Jacobsthal();
		Jacobsthal(const Jacobsthal& other);
		Jacobsthal &operator=(const Jacobsthal& other);
		size_t operator[](size_t index);

		void reset(void);

		//iterators
		class Iterator {
			public:
				Iterator(Jacobsthal& parent, size_t index);
				size_t operator*();
				Iterator& operator++();
				bool operator!=(const Iterator& other) const;

			private:
				Jacobsthal*	_parent;
				size_t		_index;
		};
		Iterator begin(void);
		Iterator end(void);

	private:
		
		std::vector<size_t> _sequence;
		std::vector<size_t> _numbers;

		void generate_next(void);
};
