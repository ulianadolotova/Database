#pragma once


#include "date.h"

#include <memory>


enum class Comparison {

	Less,

	LessOrEqual,

	Greater,

	GreaterOrEqual,

	Equal,

	NotEqual
};


enum class LogicalOperation {

	And,

	Or
};



class Node {

public:

	virtual bool Evaluate(const Date& date, const std::string& event) const = 0;
};




class EmptyNode : public Node {

public:

	bool Evaluate(const Date& date, const std::string& event) const override;
};




class DateComparisonNode : public Node {

public:

  	DateComparisonNode(Comparison comparison, const Date& date);

  	bool Evaluate(const Date& date, const std::string& event) const override;

private:

  	const Comparison comparison_;
  	const Date       date_;
};




class EventComparisonNode : public Node {

public:

  	EventComparisonNode(Comparison comparison, const std::string& event);

  	bool Evaluate(const Date& date, const std::string& event) const override;

private:

  	const Comparison  comparison_;
  	const std::string event_;
};




class LogicalOperationNode : public Node {

public:

  	LogicalOperationNode(LogicalOperation operation, std::shared_ptr<Node> left, std::shared_ptr<Node> right);

  	bool Evaluate(const Date& date, const std::string& event) const override;

private:

  	const LogicalOperation      operation_;
  	const std::shared_ptr<Node> left_;
  	const std::shared_ptr<Node> right_;
};

