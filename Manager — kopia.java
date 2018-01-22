/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package firma.model;

/**
 *

 */
public class Manager extends Pracownik 
{
   /** zmienna bonus typu double przechowujaca premie Managera */
   private double bonus;
   /**
    * 
    * @param name zmienna typu String przechowujaca nazwisko Managera
    * @param wyp zmienna typu double przechowujaca  wyplate Managera
    */
   public Manager(String name, double wyp)
   {
        super(name,wyp);
        bonus = 0;
   
   }
  /**
   * 
   * @return bonus. Zmienna typu double
   */
   public double getBonus()
   {
        return bonus;
   }
  
 
}
