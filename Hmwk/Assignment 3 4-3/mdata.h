/* 
 * File:   mdata.h
 * Author: Keanu
 *
 * Created on April 3, 2015, 3:15 PM
 */

#ifndef MDATA_H
#define	MDATA_H

struct Mdata{
    string title;
    string director;
    int year;
    int time;
    float cost;
    float revenue;
};
struct Speaker{
    string name;
    int foNum;
    string topic;
    float fee;
};
struct Division{
    string name;
    int quarter;
    float sales;
};

#endif	/* MDATA_H */

