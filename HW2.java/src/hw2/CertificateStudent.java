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



public class CertificateStudent extends Student{
    // Attributes
    private String sMajor;
    private String studentType;
    // Constructor with Parms
    public CertificateStudent(String idNum, String fname, String lname, double age, double creditHours, String major){
        super(idNum, fname, lname, age, creditHours);
        sMajor = major;
        studentType = "Certificate Student";
    }
    //Getter for studentType
    public String getStudentType(){
        return studentType;
    }
    //Getter for sMajor
    public String getStudentMajor(){
        return sMajor;
    }
    
    // Compute Fees function
    public double computeFees(){
        final double fixedRate = 700;
        final double creditHrsRate = 300;
        double creditHrs = getStudentCreditUnits();
        double courseFees= 0.0;
        courseFees = fixedRate + (creditHrs * creditHrsRate);
        setFees(courseFees);
        return courseFees;
    }
    //Print data function
    public void printData(){
        String majorInWords = "";
        if ("s".equals(getStudentMajor().toLowerCase())){
            majorInWords = "Gaming Science";
        } else if ("m".equals(getStudentMajor().toLowerCase())){
            majorInWords = "Hotel Management";
        } else if ("a".equals(getStudentMajor().toLowerCase())){
            majorInWords = "Lounge Arts";
        } else if ("e".equals(getStudentMajor().toLowerCase())){
            majorInWords = "Beverage Engineering";
        }
            
        System.out.println("ID Number: " + getStudentIdNum());
        System.out.println("Name:      " + getStudentFirstName() + " " + getStudentLastName());
        System.out.println("Age:       " + String.valueOf(getStudentAge()));
   //     System.out.println(getStudentFirstName() + " is a " + getStudentType() + " enrolled in " + String.valueOf(getStudentCreditHours() + " credits"));
   //     System.out.println(getStudentFirstName() + " pays a fees of " + String.valueOf(getFees()));
        System.out.println(getStudentFirstName() + " major is " + majorInWords);
    }
   };