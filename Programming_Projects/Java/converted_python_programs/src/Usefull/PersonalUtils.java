package Usefull;

public class PersonalUtils {
  
  public String addCommas(Integer value, Integer sigfig){
    if (sigfig > 100){
      System.out.println("--- Input for Second Argument 'sigfig' Greater than 100 ---");
      // Raise error here
    }
    String value2 = Integer.toString(value);
    String Output = value2; // Set to Value2 only to remove warning

    return Output;
  }

}
