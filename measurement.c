#include "ruby.h"

typedef struct _meas {
	float quantity;
	char *units;
	float dimension;
	char *base_units;
} Measurement;

typedef Measurement * MeasurementPtr;

VALUE rb_cMeasurement;

static VALUE rb_meas_init(VALUE meas, int argc, VALUE* argv)
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
	
	rb_iv_set(meas, "@quantity", quantity);
	rb_iv_set(meas, "@units", units);

	return meas;
}

VALUE rb_meas_plus(VALUE x, VALUE y)
{
	//VALUE m_units, m_quantity, s_units;
	VALUE z;
	
	// if (rb_obj_is_instance_of(m_summand, rb_str_new2("Measurement"))) {
		// m_units = rb_iv_get(self, "@units");
		// s_units =  rb_iv_get(m_summand, "@units");
		// if (strcmp(m_units,s_units) == 0) {
			// rb_raise(rb_eArgError, "Input object is of type Measurememt");
		// }
		
	// }
	// else {
		// rb_raise(rb_eArgError, "Input object not of type Measurememt");
		// return 0;
	// }
	 //z = rb_meas_init(rb_cMeasurement);
	 return 0;
	
}



void Init_measurement() {
  rb_cMeasurement = rb_define_class("Measurement", rb_cObject);
  rb_define_method(rb_cMeasurement, "initialize", rb_meas_init, -1);
  rb_define_method(rb_cMeasurement, "+", rb_meas_plus, 1);
}
