/* Header_addMeterByClass @ 00123600 size 64 */

/* DWARF original prototype: Meter * Header_addMeterByClass(Header * this, MeterClass * type, uint
   param, uint column) */

Meter_3 * Header_addMeterByClass(Header *this,MeterClass_3 *type,uint param,uint column)

{
  Vector *this_00;
  Meter_3 *data_;

  this_00 = this->columns[column];
  data_ = Meter_new((Machine_2 *)this->host,param,type);
                    /* Unresolved local var: Object * data@[???]
                       Unresolved local var: wchar_t i@[???] */
  Vector_set(this_00,this_00->items,data_);
  return data_;
}

