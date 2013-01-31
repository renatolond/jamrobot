#include <cstdio>

// -------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------
class cOutput
{
 public:
  static void emit_debug(const char *msg, ...);
  static void emit_info(const char *msg, ...);
  static void emit_warning(const char *msg, ...);
  static void emit_error(const char *msg, ...);
};