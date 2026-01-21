#!/usr/bin/bash
HEADR="location_headers.h"

if [ -f "$HEADR" ]; then
  rm -f $HEADR
  echo "Old location_headers.h removed"
fi
echo "Processing headers..."
echo "#ifndef LOCATION_HEADERS_H" >> $HEADR
echo "#define LOCATION_HEADERS_H" >> $HEADR
echo "//Common locs" >> $HEADR
for i in common/*.h; do
    echo "#include \"$i\"" >> $HEADR
done
echo "//Gadukino locs" >> $HEADR
for i in gadukino/*.h; do
    echo "#include \"$i\"" >> $HEADR
done
echo "//Parents locs" >> $HEADR
for i in parents/*.h; do
    echo "#include \"$i\"" >> $HEADR
done
echo "#endif // LOCATION_HEADERS_H" >> $HEADR
echo "Generation complete..."
