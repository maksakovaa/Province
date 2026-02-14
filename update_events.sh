#!/usr/bin/bash
HEADR="events/EventHeaders.h"

if [ -f "$HEADR" ]; then
  rm -f $HEADR
  echo "Old EventHeaders.h removed"
fi
echo "Processing headers..."
echo "#ifndef EVENTHEADERS_H" >> $HEADR
echo "#define EVENTHEADERS_H" >> $HEADR
echo "//Gadukino events" >> $HEADR
for i in events/gad_events/*.h; do
    echo "#include \"../$i\"" >> $HEADR
done
echo "//Parents events" >> $HEADR
for i in events/parent_events/*.h; do
    echo "#include \"../$i\"" >> $HEADR
done
echo "#endif // EVENTHEADERS_H" >> $HEADR
echo "Generation complete..."
