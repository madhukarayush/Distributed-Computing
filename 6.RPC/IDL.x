struct values {
    float num[2];
    char operation;
};

program COMPUTE {
    version COMPUTE_VERS {
        float ADD(values) = 1;
        float SUB(values) = 2;
        float MUL(values) = 3;
        float DIV(values) = 4;
    } = 6;
} = 10;


