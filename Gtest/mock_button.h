#include "button.h"
#include <gmock/gmock.h>



class MockButton : public Button {
 public:

  MOCK_METHOD0(push, void());
  MOCK_METHOD0(release, void());

};
