module demux1_4 (
    input wire din,      // Entrada de dados
    input wire [1:0] sel, // Seletora de 2 bits (para 4 saídas)
    output wire y0,      // Saída 0
    output wire y1,      // Saída 1
    output wire y2,      // Saída 2
    output wire y3       // Saída 3
);

    assign y0 = (sel == 2'b00) ? din : 1'b0;
    assign y1 = (sel == 2'b01) ? din : 1'b0;
    assign y2 = (sel == 2'b10) ? din : 1'b0;
    assign y3 = (sel == 2'b11) ? din : 1'b0;

endmodule