// ����� ��� �����

#include "stack.h"
#include <gtest.h>

TEST(TStack, can_create_stack)
{
	ASSERT_NO_THROW(TStack<int> s);
}

TEST(TStack, can_create_stack_with_positive_lenght)
{
	ASSERT_NO_THROW(TStack<int> s(1));
}

TEST(TStack, throws_when_create_stack_with_negative_lenght)
{
	ASSERT_ANY_THROW(TStack<int> s(-1));
}

TEST(TStack, can_push_element_in_stack)
{
	TStack<int> s;

	ASSERT_NO_THROW(s.push(1));
}

TEST(TStack, can_push_elements_in_stack_more_than_original_size_suggests)
{
	TStack<int> s(3);
	s.push(1);
	s.push(2);
	s.push(3);

	ASSERT_NO_THROW(s.push(4));
}

TEST(TStack, can_pop_element_from_stack)
{
	TStack<int> s;

	s.push(1);

	EXPECT_EQ(1, s.pop());
}

TEST(TStack, throws_when_pop_element_from_empty_stack)
{
	TStack<int> s;

	s.push(1);
	s.pop();

	ASSERT_ANY_THROW(s.pop());
}

TEST(TStack, Pop_deletes_element_on_the_top_of_stack)
{
	TStack<int> s(3);

	s.push(3);
	s.push(2);
	s.push(1);

	s.pop();

	EXPECT_EQ(2, s.pop());
}

TEST(TStack, can_check_element_on_top_of_stack)
{
	TStack<int> s;

	s.push(1);

	EXPECT_EQ(1, s.peek());
}

TEST(TStack, throws_when_check_element_on_top_of_empty_stack)
{
	TStack<int> s(3);

	s.push(1);
	s.pop();

	ASSERT_ANY_THROW(s.peek());
}

TEST(TStack, CheckTop_dont_deletes_element_on_the_top_of_stack)
{
	TStack<int> s(3);

	s.push(3);
	s.push(2);
	s.push(1);

	s.peek();

	EXPECT_EQ(1, s.peek());
}

TEST(TStack, checking_empty_stack_for_emptiness_returns_true)
{
	TStack<int> s(3);

	s.push(1);
	s.pop();

	EXPECT_EQ(true, s.IsEmpty());
}

TEST(TStack, cheking_not_empty_stack_for_emptiness_returns_false)
{
	TStack<int> s(3);

	s.push(1);

	EXPECT_EQ(false, s.IsEmpty());
}

TEST(TStack, can_get_size)
{
	TStack<int> s(3);

	EXPECT_EQ(3, s.GetSize());
}

TEST(TStack, can_clean_stack)
{
	TStack<int> s;

	s.push(3);
	s.push(2);
	s.push(1);

	s.clear();

	EXPECT_EQ(true, s.IsEmpty());
}
