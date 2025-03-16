//https://neps.academy/br/exercise/2319

import java.util.Scanner;

public class Main {

    final static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int[][] estoque;
        int mTipos, nTamanhos;
        int qtdPedidos; // numero inteiro 'P' do exercício, de pedidos recebidos pela loja'
        int totalDeProdutosVendidos = 0;
        int tipo,tamanho;

        //Receber dois números M e N
        mTipos = scanner.nextInt(); nTamanhos = scanner.nextInt();
        estoque = new int[mTipos][nTamanhos];

        //Receber a quantidade de roupas do tipo i e tamanho j
        for (int i = 0; i < mTipos; i++){
            for (int j = 0; j < nTamanhos; j++){
                estoque[i][j] = scanner.nextInt();
            }
        }

        //Receber o número de pedidos que o usuário vai realizar
        qtdPedidos = scanner.nextInt();

        //Realizar pedidos
        for (int p = 0; p < qtdPedidos; p++){
            tipo = scanner.nextInt();
            tamanho = scanner.nextInt();

            if (estoque[tipo - 1][tamanho - 1] > 0) {
                estoque[tipo - 1][tamanho - 1]--;
                totalDeProdutosVendidos++;
            }
        }

        System.out.println(totalDeProdutosVendidos);
    }
}