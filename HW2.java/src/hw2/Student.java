package hw2;
/**
 * 
 */
/**
 * 
 */
//module Student.java {
//}
//package hw2;

//import java.io.*;
//
//import java.util.Scanner;
//
//import java.text.DecimalFormat;



public class Student 

{



    //Information classes for students

    private String studentIdNum;

    private String studentFirstName;

    private String studentLastName;

    private double studentAge;

    private double studentCreditUnits;

    private double studentFees;



    //Constructor

    public Student(String idNum, String firstName, String lastName, double age, double creditUnits)

    {

        this.studentIdNum = idNum;

        this.studentFirstName = firstName;

        this.studentLastName = lastName;

        this.studentAge = age;

        this.studentCreditUnits = creditUnits;

        this.studentFees = 0.0;

    }



    public void setFees(double fees)

    {

        studentFees = fees;

    }



    public String getStudentIdNum()

    {

        return studentIdNum;

    }



    public String getStudentFirstName()

    {

        return studentFirstName;

    }



    public String getStudentLastName()

    {

        return studentLastName;

    }



    public double getStudentAge()

    {

        return studentAge;

    }



    public double getStudentCreditUnits()

    {

        return studentCreditUnits;

    }



    public double getStudentFees()

    {

        return studentFees;

    }

    public double computeFees()
    {
    	return studentFees; 
    }


};
