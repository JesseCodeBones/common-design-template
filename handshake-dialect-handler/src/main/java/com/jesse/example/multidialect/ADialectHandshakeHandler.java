package com.jesse.example.multidialect;

import java.util.function.Function;

public class ADialectHandshakeHandler {
    Function<HandshakeResult, Dialect> check(){
        return result -> {
            if (result.hasError) {
                return null;
            } else {
                if (result.flag.equals("B")) {
                    return new BDialect();
                } else {
                    return null;
                }
            }
        };
    }
}
