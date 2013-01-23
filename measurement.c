#include "ruby.h"
static VALUE t_init(int argc, VALUE* argv, VALUE self)
{
	VALUE quantity, units;
	
	rb_scan_args(argc, argv, "02", &quantity, &units);
	
	if(NIL_P(quantity)){
      printf("No quantity; defaulting to 0.0\n");
      quantity = rb_float_new(0.0);
	}
	
	if(NIL_P(units)){
      printf("No quantity; defaulting to 0.0\n");
      units = rb_str_new2("%");
	}
	
	rb_iv_set(self, "@quantity", quantity);
	rb_iv_set(self, "@units", units);

	return self;
}

//static VALUE t_add(VALUE self, VALUE anObject)
//{
//  VALUE arr;
//
//  arr = rb_iv_get(self, "@arr");
//  rb_ary_push(arr, anObject);
//  return arr;
//}

VALUE cMeasurement;

void Init_measurement() {
  cMeasurement = rb_define_class("Measurement", rb_cObject);
  rb_define_method(cMeasurement, "initialize", t_init, -1);
  rb_define_method(cMeasurement, "+", t_add, 1);
}
