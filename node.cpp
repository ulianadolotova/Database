#include "node.h"


template <typename T>
bool Compare(const T& lhs, const T& rhs, Comparison cmp) {

  	switch (cmp) {

  		case Comparison::Less:

    		return lhs < rhs;

  		case Comparison::LessOrEqual:

    		return lhs <= rhs;

  		case Comparison::Equal:

    		return lhs == rhs;

  		case Comparison::NotEqual:

    		return lhs != rhs;

  		case Comparison::Greater:

    		return lhs > rhs;

  		case Comparison::GreaterOrEqual:

    		return lhs >= rhs;

    	default:

    		throw std::logic_error("Expected Comparison object");

 	}

  	return false;	
}



DateComparisonNode::DateComparisonNode(Comparison comparison, const Date& date)
	: comparison_(comparison), date_(date)
{
}



EventComparisonNode::EventComparisonNode(Comparison comparison, const std::string& event) 
	: comparison_(comparison), event_(event)
{
}



LogicalOperationNode::LogicalOperationNode(LogicalOperation operation, std::shared_ptr<Node> left, 
																	   std::shared_ptr<Node> right)
	: operation_(operation), left_(left), right_(right)
{
} 



bool EmptyNode::Evaluate(const Date& date, const std::string& event) const {

	return true;
}



bool DateComparisonNode::Evaluate(const Date& date, const std::string& event) const {

	return Compare(date, date_, comparison_);
}



bool EventComparisonNode::Evaluate(const Date& date, const std::string& event) const {

	return Compare(event, event_, comparison_);
}


bool LogicalOperationNode::Evaluate(const Date& date, const std::string& event) const {

  	switch (operation_) {

  	case LogicalOperation::And:

    	return left_->Evaluate(date, event) && right_->Evaluate(date, event);

  	case LogicalOperation::Or:

    	return left_->Evaluate(date, event) || right_->Evaluate(date, event);

    default:

    	throw std::logic_error("Expected LogicalOperation object");
  	}

  	return false;
}