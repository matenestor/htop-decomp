/* Row_updateFieldWidth @ 00122ed0 size 52 */

void Row_updateFieldWidth(RowField key,size_t width)

{
  if (0xff < width) {
    Row_fieldWidths[key] = 0xff;
    return;
  }
  if (Row_fieldWidths[key] < width) {
    Row_fieldWidths[key] = (uint8_t)width;
  }
  return;
}

