//https://neps.academy/br/exercise/566

import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    final static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int valorCompra;
        int qtdParcelas;
        int valorParcela;
        int restoDivisaoParcelas;
        ArrayList<Integer> parcelas = new ArrayList<>();

        valorCompra = scanner.nextInt();
        qtdParcelas = scanner.nextInt();

        valorParcela = valorCompra / qtdParcelas;
        restoDivisaoParcelas = valorCompra % qtdParcelas;

        for (int i = 0; i < qtdParcelas; i++){
            if (restoDivisaoParcelas > 0 && i < restoDivisaoParcelas)
                parcelas.add(i, valorParcela + 1);
            else
                parcelas.add(i, valorParcela);
            System.out.println(parcelas.get(i));
        }
    }
}