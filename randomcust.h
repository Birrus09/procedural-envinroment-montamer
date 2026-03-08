float randomnum(int &seed){
    seed = (seed * 1354 + 7391) % 4273;
    float caspita = seed / 4273.0;
    return caspita;
}
