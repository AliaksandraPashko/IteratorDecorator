#include <iterator>

template <class Category, class IteratorType, class Distance = ptrdiff_t,
	class Pointer = IteratorType * , class Reference = IteratorType & >

	struct Iterator {

	typedef IteratorType value_type;
	typedef Distance  difference_type;
	typedef Pointer   pointer;
	typedef Reference reference;
	typedef Category  iterator_category;

};


template<typename FilterFunc, typename IteratorType>
class IteratorDecorator : public Iterator<std::forward_iterator_tag, IteratorType> 
{
	FilterFunc filter_ = 0;
	IteratorType current_ = nullptr;
	IteratorType end_ = nullptr;

	void next_element()
	{
		do
		{
			current_++;
		} while (current_ != end_ && !filter_(*current_));
	}

public:

	IteratorDecorator(FilterFunc filter, IteratorType begin, IteratorType end)
		: filter_(filter), current_(begin), end_(end)
	{
		if (current_ != end_)
		{
			next_element();
		}
	}

	IteratorDecorator(const IteratorDecorator &obj)
		: filter_(obj.filter_), current_(obj.current_), end_(obj.end_) {}

	IteratorDecorator& operator ++()
	{	
		if (current_ == end_)
			return *this;
		next_element();
		return *this;
	}

	IteratorDecorator operator ++(int)
	{
		IteratorDecorator it(*this);
		next_element();
		return it;
	}

	decltype(*current_) operator * ()
	{
		return *current_;
	}

	IteratorType operator -> ()
	{
		return current_;
	}

	bool operator == (const IteratorDecorator &compare_it) const
	{
		return current_ == compare_it.current_;
	}

	bool operator != (const IteratorDecorator &compare_it) const
	{
		return current_ != compare_it.current_;
	}

	IteratorDecorator& operator = (const IteratorDecorator &assign_it )
	{
		this->filter_ = assign_it.filter_;
		this->current_ = assign_it.current_;
		this->end_ = assign_it.end_;
		return *this;
	}

	~IteratorDecorator() {}
};