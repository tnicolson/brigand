
#include <brigand/functions/identity.hpp>
#include <type_traits>

static_assert( std::is_same<int**&&, brigand::identity<int**&&>>::value, "invalid identity");
static_assert( std::is_same<void, brigand::identity<void>>::value, "invalid identity");
