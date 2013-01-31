#include "output.h"

#include <stdarg.h>


// -------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------
void cOutput::emit_debug(const char *msg, ...)
{
  #pragma omp critical(output)
  {
    va_list args;
    va_start(args, msg);
    vprintf(msg, args);
    va_end(args);
    printf("\n");
  }
}

// -------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------
void cOutput::emit_info(const char *msg, ...)
{
  #pragma omp critical(output)
  {
    va_list args;
    va_start(args, msg);
    vprintf(msg, args);
    va_end(args);
    printf("\n");
  }
}

// -------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------
void cOutput::emit_warning(const char *msg, ...)
{
  #pragma omp critical(output)
  {
    va_list args;
    va_start(args, msg);
    vprintf(msg, args);
    va_end(args);
    printf("\n");
  }
}

// -------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------
void cOutput::emit_error(const char *msg, ...)
{
  #pragma omp critical(output)
  {
    va_list args;
    va_start(args, msg);
    vfprintf(stderr, msg, args);
    va_end(args);
    printf("\n");
  }
}
