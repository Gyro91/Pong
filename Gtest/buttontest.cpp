#include "mock_button.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "player.h"


using ::testing::AtLeast;
TEST(PainterTest, CanDrawSomething) {
	MockButton turtle;
	EXPECT_CALL(turtle, release())
	.Times(AtLeast(1));

	Player player(&turtle);

	EXPECT_TRUE(player.DrawCircle(0, 0, 10));
}

int main(int argc, char** argv) {
	// The following line must be executed to initialize Google Mock
	// (and Google Test) before running the tests.
	::testing::InitGoogleMock(&argc, argv);
	return RUN_ALL_TESTS();
}
