package hw2;

import java.io.BufferedReader;
//import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
/*
 * To ensure you get graded correctly by autograder, 
 * DO NOT change the file name, method names, and provided skeleton code.
 * Only fill in your code where there is a TODO comment.
 * Use the provided variables in the reportBuilder code. 
 * Check if your generateReport() output is equal to hw2_output.txt 
 * 
 * Questions or comments? Direct them to TA (Ty Feng)
 * 
 */
public class Test {

	public static String generateReport() {
		StringBuilder reportBuilder = new StringBuilder();
		// TODO:
		// Read hw2.txt line by line

		// For each record, create an instance in the corresponding class (FinAssist,
		// NoFinAssist, Degree, etc.)

		// Save all records to a Student[] array. Student is the interface for all the
		// classes you make.
		Student[] students = new Student[100]; // save all the student record objects here
		String currLine;

		// DO NOT ADD, CHANGE, OR DELETE ANY reportBuilder code. Use the provided variables.
		// INDIVIDUAL REPORTS, listing of all students and the fees they have each been
		// assessed
		

//		int student_fee = 0; // TODO: Change this! Assign its value in the iteration below and use the
								// provided print statement
		double student_fee = 0;
		String student_name = ""; // TODO: Change this! Assign its value in the iteration below and use the
									// provided print statement
		int studentNumber = 0;
		BufferedReader reader = null;
		
		try {
			reader = new BufferedReader(new FileReader("hw2.txt"));
			while((currLine = reader.readLine()) != null)
			{
				String[] segment = currLine.split(";");
				
				String studentId = segment[0];
				student_name = segment[1] + " " + segment[2];
				double studentAge = Double.parseDouble(segment[3]);
				double creditUnits = Double.parseDouble(segment[4]);
				char degree = segment[5].charAt(0);
				if(degree == 'Y')
				{
					String studentMajor = segment[6];
					String academicStanding = segment[7];
					char finAssist = segment[8].charAt(0);
					if(finAssist == 'Y')
					{
						double studentDollarValue = Double.parseDouble(segment[9]);
						students[studentNumber] = new dsStudentsWithFinAssist(studentId, segment[1], segment[2], studentAge, creditUnits, studentMajor, academicStanding, studentDollarValue);
					}
					else
					{
						students[studentNumber] = new dsStudents(studentId, segment[1], segment[2], studentAge, creditUnits, studentMajor, academicStanding);
						
					}
						

				}
				else if(degree == 'N')
				{
					char studentType = segment[6].charAt(0);
					if(studentType == 'C')
					{
						
						String studentMajor = segment[7];
						students[studentNumber] = new CertificateStudent(studentId, segment[1], segment[2], studentAge, creditUnits, studentMajor);
					}
					else
					{
						students[studentNumber] = new SeniorCitizen(studentId, segment[1], segment[2], studentAge, creditUnits);
					}
					
				}
				else
				{
					
				}
				
				
				studentNumber++;
			}
		}
		catch (IOException e) 
		{
			e.printStackTrace();
		}
		// Print out first and last name and fee amount
		reportBuilder.append("Summary of each student's fees assessed: \n\n");
		// TODO: iterate over all Student records and compute the individual student_fee. Assign student_name.
		// TODO: put the following line in your for/while loop so that every student's fee gets printed
//		reportBuilder.append(student_name + " has $" + String.format("%,d", (int)(student_fee)) + " fees assessed \n");
		
		
		
		// SUMMARY REPORT of fees assessed for each of the four types of student
		int degree_nofin_fees = 0;
		int degree_fin_fees = 0;
		int certificate_fees = 0;
		int senior_fees = 0;
		int total_fees = 0;
		for(Student student: students)
		{
			if(student == null)break;
			student_fee = student.computeFees();
			student_name = student.getStudentFirstName() + " " + student.getStudentLastName();
			reportBuilder.append(student_name + " has $" + String.format("%,d", (int)student_fee) + " fees assessed \n");
			
			if(student instanceof dsStudentsWithFinAssist)
			{
				degree_fin_fees += student_fee;
			}
			else if(student instanceof dsStudents)
			{
				degree_nofin_fees += student_fee;
			}
			else if(student instanceof CertificateStudent)
			{
				certificate_fees += student_fee;
			}
			else
			{
				senior_fees += student_fee;
			}
			
			total_fees += student_fee;
//			reportBuilder.append(student_name + " has $" + String.format("%,d", (int)(student_fee)) + " fees assessed \n");
			
		}
		// TODO: Calculate the fees values by iterating through all students
//		reportBuilder.append(student_name + " has $" + String.format("%,d", (int)(student_fee)) + " fees assessed \n");
		
		// Print out the fee amounts
		reportBuilder.append("\n\n");
		reportBuilder.append("Summary of all student fees assessed: \n\n");
		reportBuilder.append(
				"Degree-seeking students without financial assistance: $" + String.format("%,d", degree_nofin_fees) + "\n");
		reportBuilder
				.append("Degree-seeking students with financial assistance: $" + String.format("%,d", degree_fin_fees) + "\n");
		reportBuilder.append("Certificate students: $" + String.format("%,d", certificate_fees) + "\n");
		reportBuilder.append("Senior citizens: $" + String.format("%,d", senior_fees) + "\n\n");
		reportBuilder.append("Total fees assessed: $" + String.format("%,d", total_fees));

		return reportBuilder.toString();
	}

	public static void main(String[] args) {
		System.out.println(generateReport());
	}
}
