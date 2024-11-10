#include "vec.hpp"
#include "subscriber.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using ::testing::_;
using ::testing::ExpectationSet;


TEST(Vec, plus)
{
	Vec<float> v1(1, 3);
	Vec<float> v2(5, 6);

	auto v3 = v1 + v2;

	EXPECT_TRUE(v3.x == 6);
	EXPECT_TRUE(v3.y == 9);


}

TEST(Vec, minus)
{
	Vec<float> v1(1, 3);
	Vec<float> v2(5, 6);
	
	auto v4 = v1 - v2;

	EXPECT_TRUE(v4.x == -4);
	EXPECT_TRUE(v4.y == -3);
}

TEST(Vec, NotEq)
{
	Vec<float> v1(1, 3);
	Vec<float> v2(5, 6);


	EXPECT_FALSE(v1 == v2);
}

TEST(Vec, Eq)
{
	Vec<float> v1(5, 6);
	Vec<float> v2(5, 6);


	EXPECT_TRUE(v1 == v2);
}



class TestSubscriber : public Subscriber
{
public:
	TestSubscriber() : Subscriber() {}
	~TestSubscriber() {}
	
	//void notify(std::weak_ptr<Publisher> publisher) 
	MOCK_METHOD1(notify, void(std::weak_ptr<Publisher>));

};



TEST(Subscriber, simple) {

	std::shared_ptr<Publisher> pub (new Publisher);
	std::shared_ptr<TestSubscriber> sub(new TestSubscriber);
	std::shared_ptr<TestSubscriber> sub2(new TestSubscriber);

	pub->addSubscriber(sub);
	pub->addSubscriber(sub2);
	{

		//EXPECT_EQ(sub->vizvan, true);
		//EXPECT_EQ(sub2->vizvan, true);
		EXPECT_CALL((*sub), notify(_)).Times(2);
		EXPECT_CALL((*sub2), notify(_)).Times(2);
		pub->emit();
		pub->emit();
	}


}
