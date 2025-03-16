//https://neps.academy/br/exercise/2320

import java.util.*;

public class Main {

    final static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        List<Integer> sequenciaA = new ArrayList<>();
        List<Integer> subSequenciaB = new ArrayList<>();
        int tamA;
        int tamB;



        //Receber o tamanho das sequencias
        tamA = scanner.nextInt();
        tamB = scanner.nextInt();



        //Receber os numeros pras sequencias
        for (int i = 0; i < tamA; i++){
            sequenciaA.add(scanner.nextInt());
        }

        for (int i = 0; i < tamB; i++){
            subSequenciaB.add(scanner.nextInt());
        }



        //Verificar se contem a subsequencia
        if (sequenciaContemSubsequenciaNaOrdem(sequenciaA, subSequenciaB))
            System.out.print("S");
        else
            System.out.print("N");
    }


    
    public static boolean sequenciaContemSubsequenciaNaOrdem(List<Integer> sequencia, List<Integer> subsequencia){
        int indexSequencia = 0;

        for (Integer num : subsequencia) {
            for (; ; indexSequencia++) {
                if (indexSequencia == sequencia.size())
                    return false;
                else {
                    if (Objects.equals(sequencia.get(indexSequencia), num))
                        break;
                }
            }
        }
        return true;
    }
}