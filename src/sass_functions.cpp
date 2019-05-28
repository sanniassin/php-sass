#include "sass_functions.h"

union Sass_Value* call_fn_pow(const union Sass_Value* psv_args, Sass_Function_Entry cb, struct Sass_Compiler* options)  {
	if(sass_check_args("nn", 2, psv_args)) {
		union Sass_Value* psv_i = sass_list_get_value(psv_args, 0);
		union Sass_Value* psv_n = sass_list_get_value(psv_args, 1);
		double i = sass_number_get_value(psv_i);
		double n = sass_number_get_value(psv_n);
		return sass_make_number(pow(i, n), sass_number_get_unit(psv_i));
	}
	return sass_report_error("Argument in pow is not right!");
}
