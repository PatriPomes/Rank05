#pragma once

#include "given/searchable_bag.hpp"

class set 
{
	private:
		searchable_bag& bag;

	public:
		set(searchable_bag& s_bag);
		
		set() = delete;
		set(const set& other) = delete;
		set& operator=(const set& other) = delete;
		//~set();

		bool has(int) const;
		void insert (int);
		void insert (int *, int);
		void print () const;
		void clear ();

		const searchable_bag& get_bag() const;
};

