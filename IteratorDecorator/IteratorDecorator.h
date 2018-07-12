
template<typename FilterFunc, typename IteratorType>
class IteratorDecorator
{
	FilterFunc filter_;
	IteratorType iterator_;
public:
	IteratorDecorator(FilterFunc filter, IteratorType iterator)
		: filter_(filter), iterator_(iterator)
	{
		if (!filter_(*iterator_))
		{
			while (!filter_(*this->iterator_))
				iterator_++;
		}
	}

	IteratorDecorator(const IteratorDecorator &obj)
	{
		filter_ = obj.filter_;
		iterator_ = obj.iterator_;
	}
/*
	IteratorDecorator operator ++(IteratorDecorator& previous_it)
	{
		
		IteratorDecorator new_it(this->filter_, this->iterator_);
		while (!filter_(*this->iterator_) && )
			previous_it->iterator_++;	
			
	}
	*/

	decltype(*iterator_) operator * ()
	{
		return *iterator_;
	}

	IteratorType operator -> ()
	{
		return iterator_;
	}

	bool operator == (const IteratorDecorator &compare_it) const
	{
		return this->iterator_ == compare_it.iterator_;
	}

	bool operator != (const IteratorDecorator &compare_it) const
	{
		return this->iterator_ != compare_it.iterator_;
	}

	~IteratorDecorator() {}
};