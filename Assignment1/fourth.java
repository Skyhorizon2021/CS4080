/*
Name: Loc Nguyen
Program Purpose: Add, subtract, multiply 2 matrices using Class
*/

import java.util.Random;
import java.util.Scanner;
import java.util.concurrent.TimeUnit;

public class fourth {
    public static void printMenu()
    {
        System.out.println("\n----- Select an operation -----\n(1) Addition\n(2) Subtraction\n(3) Multiplication\n(4) Enter two new matrices\n(5) Exit");
        System.out.print("Enter your choice: ");
    }
    public static void main(String[] args) 
    {
        Scanner userInput = new Scanner(System.in);
        //initialize matrix 1
        System.out.println("Enter rows and columns for matrix 1: ");
        int m1_row = userInput.nextInt();
        int m1_col = userInput.nextInt();
        //Limit matrix size to 100x100
        while(m1_row >100 || m1_col >100)
        {
            System.out.println("Enter rows and columns for matrix 2: ");
            m1_row = userInput.nextInt();
            m1_col = userInput.nextInt();
        }
        Matrix m1 = new Matrix(m1_row, m1_col);
        //Enter elements into matrix 1
        //System.out.println("Enter elements of matrix 1: ");
        m1.getElements();
        //System.out.println("\nMatrix 1:");
        //m1.printMatrix();
        //initialize matrix 2
        System.out.println("Enter rows and columns for matrix 2: ");
        int m2_row = userInput.nextInt();
        int m2_col = userInput.nextInt();
        //Limit matrix size to 100x100
        while(m2_row >100 || m2_col >100)
        {
            System.out.println("Enter rows and columns for matrix 2: ");
            m2_row = userInput.nextInt();
            m2_col = userInput.nextInt();
        }
        Matrix m2 = new Matrix(m2_row, m2_col);
        //Enter elements into matrix 2
        //System.out.println("Enter elements of matrix 2: ");
        m2.getElements();
        // System.out.println("\nMatrix 2:");
        // m2.printMatrix();

        //print menu and choice selection
        printMenu();
        int choice = userInput.nextInt();
        //terminate when choice = 5
        while(choice != 5)
        {
            if(choice==1)
            {
                //check matrices size
                if ((m1_row == m2_row) && (m1_col == m2_col))
                {
                    //dynamic allocation for sum matrix
                    Matrix sum_matrix = new Matrix(m1_row, m1_col);
                    sum_matrix = m1.addMatrix(m2);
                    System.out.println("\nOutput Matrix:");
                    sum_matrix.printMatrix();
                }
                else
                {
                    System.out.println("\nInvalid addition operation based on matrix size!\n");
                }
            }
            else if(choice==2)
            {
                //check matrices size
                if ((m1_row == m2_row) && (m1_col == m2_col))
                {
                    //dynamic allocation for difference matrix
                    Matrix diff_matrix = new Matrix(m1_row, m1_col);
                    diff_matrix = m1.subMatrix(m2);
                    System.out.println("\nOutput Matrix:");
                    diff_matrix.printMatrix();
                }
                else
                {
                    System.out.println("\nInvalid subtraction operation based on matrix size!\n");
                }
            }
            else if(choice==3)
            {
                //check matrices size
                if (m1_col == m2_row)
                {
                    //dynamic allocation for product matrix
                    Matrix product_matrix = new Matrix(m1_row, m2_col);
                    long startTime = System.nanoTime();
                    product_matrix = m1.mulMatrix(m2);
                    long stopTime = System.nanoTime();
                    System.out.println("\nOutput Matrix:");
                    product_matrix.printMatrix();
                    long executionTime = stopTime - startTime;
                    System.out.println("Execution time(ns): "+executionTime);
                }
                else
                {
                    System.out.println("\nInvalid multiplication operation based on matrix size!\n");
                }
            }
            else if(choice==4)
            {
                //initialize matrix 1
                System.out.println("Enter rows and columns for matrix 1: ");
                m1_row = userInput.nextInt();
                m1_col = userInput.nextInt();
                //Limit matrix size to 100x100
                while(m1_row >100 || m1_col >100)
                {
                    System.out.println("Enter rows and columns for matrix 2: ");
                    m1_row = userInput.nextInt();
                    m1_col = userInput.nextInt();
                }
                //update number of rows and columns for matrix 1
                m1.setRow(m1_row);
                m1.setCol(m1_col);
                //Enter elements into matrix 1
                //System.out.println("Enter elements of matrix 1: ");
                m1.getElements();
                // System.out.println("\nMatrix 1:");
                // m1.printMatrix();
                //initialize matrix 2
                System.out.println("Enter rows and columns for matrix 2: ");
                m2_row = userInput.nextInt();
                m2_col = userInput.nextInt();
                //Limit matrix size to 100x100
                while(m2_row >100 || m2_col >100)
                {
                    System.out.println("Enter rows and columns for matrix 2: ");
                    m2_row = userInput.nextInt();
                    m2_col = userInput.nextInt();
                }
                //update number of rows and columns for matrix 2
                m2.setRow(m2_row);
                m2.setCol(m2_col);
                //Enter elements into matrix 2
                //System.out.println("Enter elements of matrix 2: ");
                m2.getElements();
                // System.out.println("\nMatrix 2:");
                // m2.printMatrix();
            }
            printMenu();
            choice = userInput.nextInt();
        }
        if(choice == 5)
        {
            System.out.println("Program terminated!");
        }
        //close Scanner
        userInput.close();
    }
}


class Matrix {
    private int row;
    private int col;
    private float a_matrix[][];
    //function to print matrix
    public void printMatrix()
    {
        
        for(int i=0; i<getRow(); i++)
        {
            for(int j=0; j<getCol(); j++)
            {
                System.out.print("\t" + getMatrix()[i][j]); 
            }
            System.out.println();
        }
    }
    //setter row and column
    public void setRow(int input_row)
    {
        row = input_row;
    }
    public void setCol(int input_col)
    {
        col = input_col;
    }
    //getter for matrix,row, and column
    public float[][] getMatrix()
    {
        return a_matrix;
    }
    public int getRow()
    {
        return row;
    }
    public int getCol()
    {
        return col;
    }
    //matrix constructor
    public Matrix(int input_row,int input_col)
    {
        setRow(input_row);
        setCol(input_col);
        a_matrix = new float[getRow()][getCol()];
    }
    //function to get or generate random elements
    public void getElements()
    {
        //Scanner userInput = new Scanner(System.in);
        Random rand = new Random();   
        for(int i=0;i<getRow();i++)
        {
            for(int j=0;j<getCol();j++)
            {
                //getMatrix()[i][j] = userInput.nextFloat();
                getMatrix()[i][j] = rand.nextFloat(1,100);
            }
        }
    }
    //function to add 2 matrices
    public Matrix addMatrix(Matrix other_matrix)
    {
        Matrix sum_matrix = new Matrix(getRow(), getCol());
        for (int i=0;i<getRow();i++)
        {
            for (int j=0;j<getCol();j++)
            {
                sum_matrix.getMatrix()[i][j] = getMatrix()[i][j] + other_matrix.getMatrix()[i][j];
            }
        }
        return sum_matrix;
    }
    //fucntion to subtract 2 matrices
    public Matrix subMatrix(Matrix other_matrix)
    {
        Matrix diff_matrix = new Matrix(getRow(), getCol());
        for (int i=0;i<getRow();i++)
        {
            for (int j=0;j<getCol();j++)
            {
                diff_matrix.getMatrix()[i][j] = getMatrix()[i][j] - other_matrix.getMatrix()[i][j];
            }
        }
        return diff_matrix;
    }
    //function to multiply 2 matrices
    public Matrix mulMatrix(Matrix otheMatrix)
    {
        Matrix product_matrix = new Matrix(getRow(), otheMatrix.getCol()); 
        for(int i=0;i<getRow();i++)
        {
            for(int j=0;j<otheMatrix.getCol();j++)
            {
                for(int k=0;k<getCol();k++)
                {
                    product_matrix.getMatrix()[i][j] += getMatrix()[i][k] * otheMatrix.getMatrix()[k][j]; 
                }
            }
        }
        return product_matrix;
    }
}