#!/bin/sh

echo  """BEGIN:VCALENDAR
VERSION:2.0
METHOD:PUBLISH
PRODID:-//hack//toke//kraus v1.0//EN"""

for doy in {0..365} ; do
    dayk=$(kraus  $doy | awk -- '{ print $2" "$8 }')
    day=$(echo $dayk | awk -- '{split($1,a,"."); print a[1]}')
    month=$(echo $dayk | awk -- '{split($1,a,"."); print a[2]}')
    floor=$(echo $dayk | awk -- '{ print $2 }')
a="""BEGIN:VEVENT
UID:2015${month}${day}T120000-123000@toke.de
URL:http://jautz.org/kraus/
DTSTAMP;TZID=Europe/Berlin:2015${month}${day}T000000
DTSTART;TZID=Europe/Berlin:2015${month}${day}T120000
DTEND;TZID=Europe/Berlin:2015${month}${day}T123000
RRULE:FREQ=YEARLY;INTERVAL=1
SUMMARY:K.R.A.U.S.: ${floor}. Stock
CATEGORIES:KRAUS
LOCATION:EFS 9: ${floor}. Stock
TRANSP:TRANSPARENT
END:VEVENT"""

/bin/echo  "$a"

done

echo ""END:VCALENDAR""
