package zjz;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Test {

    public static void main(String[] args) {
        // TODO Auto-generated method stub
        LRTable lrTable = new LRTable();
        String filepath = "C:\\input.txt";
        try {
            Scanner scanner = new Scanner(new File(filepath));
            
            String string = scanner.nextLine();
            lrTable.start = string.charAt(0);
            string = scanner.nextLine();
            lrTable.setfinality(string);
            string = scanner.nextLine();
            lrTable.setunfinality(string);  
          
            lrTable.arrayList.add("O->"+lrTable.start);
            while(scanner.hasNext()){
                string = scanner.nextLine();
                lrTable.arrayList.add(string);
            }
            scanner.close();
            LR.lr(lrTable);
        } catch (FileNotFoundException e) {
            // TODO Auto-generated catch block
            System.out.println("文件未找到");
            e.printStackTrace();
        }
        lrTable.PrintTable();
        lrTable.PrintPath();
        
    }

}
