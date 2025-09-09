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

import java.io.*;

import java.util.Scanner;

import java.text.DecimalFormat;



public class SeniorCitizen extends Student

{

    private String studentType;

    public SeniorCitizen(String idNum, String firstName, String lastName, double age, double creditUnits)

    {

        super(idNum, firstName, lastName, age, creditUnits);

        studentType = "Senior citizen"; 

    }



    public String getStudentType()

    {

        return studentType;

    }

    public double computeFees()

    {

        final double fixedAssessment = 100;

        final double addAssessment = 50;

        double creditUnits = getStudentCreditUnits();

        double courseFee = 0.0;

        if (creditUnits <= 6.0)

        {

            courseFee = fixedAssessment;

        }

        else

        {

            courseFee = fixedAssessment + (addAssessment * (creditUnits - 6.0));

        }

            setFees(courseFee);
            
            return courseFee;

    }



    //Senior Students Data

    public void printData()

    {

        System.out.println("ID #: " + getStudentIdNum());

        System.out.println("Name: " + getStudentFirstName() + " " + getStudentLastName());

        System.out.println("Age:  " + String.valueOf(getStudentAge()));

//        System.out.
        
    }
};