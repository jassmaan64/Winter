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



public class dsStudentsWithFinAssist extends dsStudents

{

    private double studentDollarValue;

    public dsStudentsWithFinAssist(String idNum, String firstName, String lastName, double age, double creditUnits, String major, String academicStanding, double dollarValue)

    {

        super(idNum, firstName, lastName, age, creditUnits, major, academicStanding);

        studentDollarValue = dollarValue;

    }



    public double getFinAssist()

    {

        return studentDollarValue;

    }



    public String toString()

    {

        return "Id #: " + getStudentIdNum() + ", Name: " + getStudentFirstName() + " " + getStudentLastName() + ", Total Fees: $" + String.valueOf(getStudentFees());

    }



    //fee function for degree students with financial assistance

    public double computeFees()

    {

        final double athleticFee = 100;

        final double unionFee = 50;

        double creditUnitRate = 275;

        double creditUnits = getStudentCreditUnits();

        double courseFee = 0.0;

        double totalFee = 0.0;

        if (creditUnits > 12.0)

        {

            courseFee = creditUnitRate * 12;

        }

        else

        {

            courseFee = creditUnitRate * creditUnits;

        }

        totalFee = courseFee + unionFee + athleticFee;

        totalFee = totalFee - studentDollarValue;

        if (totalFee < 0)

        {

            setFees(0);

        }

        else

        {

            setFees(totalFee);

        }
        if(totalFee < 0)return 0;
        return totalFee;

    }



    //print data method

    public void printData()

    {

        String majorRef = "";

        String academicStandingRef = "";

        if ("s".equals(getStudentMajor().toLowerCase()))

        {

            majorRef = "Gaming Science";

        }

        else if ("m".equals(getStudentMajor().toLowerCase()))

        {

            majorRef = "Hotel Management";

        }

        else if ("a".equals(getStudentMajor().toLowerCase()))

        {

            majorRef = "Lounge Arts";

        }

        else if ("e".equals(getStudentMajor().toLowerCase()))

        {

            majorRef = "Beverage Engineering";

        }



        if ("g".equals(getStudentAcademicStanding().toLowerCase()))

        {

            academicStandingRef = "Good";

        }

        else if ("w".equals(getStudentAcademicStanding().toLowerCase()))

        {

            academicStandingRef = "Warning";

        }

        else if ("p".equals(getStudentAcademicStanding().toLowerCase()))

        {

            academicStandingRef = "Probation";

        }

        System.out.println("ID #: " + getStudentIdNum());

        System.out.println("Name:      " + getStudentFirstName() + " " + getStudentLastName());

        System.out.println("Age:       " + String.valueOf(getStudentAge()));

        System.out.println(getStudentFirstName() + " is a degree-seeking student, enrolled in " + String.valueOf(getStudentCreditUnits() + " credit Units"));

        System.out.println(getStudentFirstName() + " major is " + majorRef);

        System.out.println(getStudentFirstName() + " is in " + academicStandingRef + " academic standing");

        System.out.println(getStudentFirstName() + " receives $" + String.valueOf(getFinAssist()) + "in financial assistance \n");

    }

};

