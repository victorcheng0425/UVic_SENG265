#!/usr/bin/env python3
#
#  In addition to the datetime library module, this exercise uses the ical date and time format
#  See https://www.kanzaki.com/docs/ical/dateTime.html for more info on this format.  
#
#  example: 10:35 pm, Feb 25, 2020 would be represented in ical format as:  20200225T223500 


import datetime


def main():
    	
    # STEP 1
    dt1_i = "20190523T051252"
    # use extract() to extract extract year, month, day, hour, minute and second and print to screen with print commands in the main
    y, mon, d, h, m, s = extract(dt1_i)
    print("Year: ",y, "month: ",mon, "day:",d, "hour: ",h, "minute: ",m, "second: ",s)
    print("Year: {}, Month: {}, Day: {}, Hour: {}, Minute: {}, Second: {}".format(y, mon, d, h, m, s))
 
    # STEP 2
    # create a datetime object using any date and time and print it
    now = datetime.datetime.now()
    print(now)
    #print(datetime.datetime(y, mon, d, h, m, s, 0, 1))

    # STEP 3
    dt2_i = "20150223T120223"
    # write a function ical_to_datetime() which take ical date and time and converts it into a datetime object
    # use extract() and datetime.datetime. Refer to the online documentation for datetime module
    # print the datetime object in the main
    obj = ical_to_datetime(dt2_i)
    print(obj)
    print("step 3 done")
    
    # STEP 4
    # create 4 datetime objects, dt1, dt2, dt3 and dt4 with any date and times you choose
    # add them to a list l1
    # print l1
    # sort l1
    # print l1
    dt1 = "20190623T111113"
    dt2 = "20180523T111116"
    dt3 = "20190523T111115"
    dt4 = "20190923T111111"
    lis = [ical_to_datetime(dt1), ical_to_datetime(dt2), ical_to_datetime(dt3), ical_to_datetime(dt4)]
    print(lis)
    lis.sort()
    for date in lis:
    	print(date)
	
    print("Step 4 done")
    # STEP 5
    # create a timedelta object tdelta (using datetime.timedelta) of duration 5 hours
    # create a datetime object dtime of any date and time of your choosing
    dtime = datetime.datetime(2012, 5, 6, 2, 25, 36)
    print(dtime)
    tdelta = datetime.timedelta(hours = 5)
    t1 = dtime + tdelta
    t2 = dtime - tdelta
    print("t1= dtime + tdelta is ", t1)
    print("t2= dtime - tdelta is ", t2)
    print("Step 5 done")
    # Notice the outcome of the 2 print statements above
    

    # STEP 6
    # create a timedelta object with weeks = 1, hours = 2, seconds = 34, minutes = 34
    tdelta = datetime.timedelta(weeks = 1, hours = 2, seconds = 34, minutes = 34)
    # Add / Substract dtime and tdelta and see what happens
    t1 = dtime + tdelta
    print("dtime + tdelta is ", t1)
    
    # STEP 7
    # Refer to the function datetime_change() and complete implementation
    dtime = datetime.datetime(2012, 5, 6, 2, 25, 36)
    print(dtime)
    dtime = datetime_delta(dtime, "forward", hours = 24)
    print(dtime)
    dtime = datetime_delta(dtime, "forward", hours = 2, weeks = 1, seconds = 25)
    print(dtime)
    print("Step 7 Done")


    # STEP 8
    dtime = datetime.datetime(2012, 5, 6, 2, 25, 36)
    print("dtime: {}".format(dtime))
    # create an ical date and time string from dtime
    year = dtime.year
    month = dtime.month
    day = dtime.day
    hour = dtime.hour
    minute = dtime.minute
    second = dtime.second
    #print("{}{0:0=2d}{0:0=2d}T{0:0=2d}{0:0=2d}{0:0=2d}".format(year, month, day, hour, minute, second))
    print("{}{:0=2d}{:0=2d}T{:0=2d}{:0=2d}{:0=2d}".format(year, month, day, hour, minute, second))

    # FINAL STEP
    ical_dt = "20251222T022554"
    # write a function increment_days() that takes 2 parameters,
    # one is an ical date and time (ical_dt)
    # second is a numbers of days
    # it increments the ical date and time by the number of days and print out the resulting ical date and time.
    # use the function you have written so far.
    print(ical_dt)
    ical_dt = increment_days(ical_dt, 5)
    print(ical_dt)


# STEP 1
# define a function extract() that will extract year, month, day, hour, minute and second from an ical date and time
def extract(obj):
    #dt1_i = "20190523T051252"
    year = obj[0:4]
    month = obj[4:6]
    day = obj[6:8]
    hour = obj[9:11]
    minute = obj[11:13]
    second = obj[13:]
    return year, month, day, hour, minute, second
	
# STEP 3
# define a function ical_to_datetime that will take a ical data and time as a parameter and will return a datetime object with the same date an time as the input parameter
def ical_to_datetime(ical):
    y, mon, d, h, m, s = extract(ical)
    return datetime.datetime(int(y), int(mon), int(d), int(h), int(m), int(s))
# STEP 7
    '''
        Complete the implementation of datetime_change()
        dtime is a datetime object that will be modified by a time interval
        mode indicates whether dtime is modifed by moving its time forward or backward.
        The other parameters are the time interval by which dtime is to be modified.

    '''
def datetime_delta(dtime, mode, days=0, seconds=0, microseconds=0, milliseconds=0, minutes=0, hours=0, weeks=0):
	 if mode is "forward":
	 	print("Forward inside function")
	 	return dtime + datetime.timedelta(days, seconds, microseconds, milliseconds, minutes, hours, weeks)
	 else:
	 	print("Backward inside function")
	 	return dtime - datetime.timedelta(days, seconds, microseconds, milliseconds, minutes, hours, weeks)

    # COMPLETE IMPLEMENTATION

# FINAL STEP
def increment_days(ical_dt, dincrement):
    d = datetime_delta(ical_to_datetime(ical_dt), "forward", days = dincrement)
    print(d)
    years = str(d.year)
    month = str(d.month)
    if len(month) == 1:
    	month = "0" + month
    day = str(d.day)
    if len(day) == 1:
    	day = "0" + mondayth
    hour = str(d.hour)
    if len(hour) == 1:
    	hour = "0" + hour
    minute = str(d.minute)
    if len(minute) == 1:
    	minute = "0" + minute
    second = str(d.second)
    if len(second) == 1:
    	second = "0" + second
	     
    strr = years + month + day + "T" + hour + minute + second
    return strr

    

if __name__ == "__main__":
    main()
