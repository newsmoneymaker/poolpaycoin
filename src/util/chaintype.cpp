// Copyright (c) 2023 The Bitcoin Core developers
// Copyright (c) 2024 The Scash developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <util/chaintype.h>

#include <cassert>
#include <optional>
#include <string>

std::string ChainTypeToString(ChainType chain)
{
    switch (chain) {
    case ChainType::MAIN:
        return "main";
    case ChainType::TESTNET:
        return "test";
    case ChainType::SIGNET:
        return "signet";
    case ChainType::REGTEST:
        return "regtest";
    // !SCASH
    case ChainType::POOLPAYMAIN:
        return "poolpay";
    case ChainType::POOLPAYTESTNET:
        return "poolpaytestnet";
    case ChainType::POOLPAYREGTEST:
        return "poolpayregtest";
    // !SCASH END
    }
    assert(false);
}

std::optional<ChainType> ChainTypeFromString(std::string_view chain)
{
    if (chain == "main") {
        return ChainType::MAIN;
    } else if (chain == "test") {
        return ChainType::TESTNET;
    } else if (chain == "signet") {
        return ChainType::SIGNET;
    } else if (chain == "regtest") {
        return ChainType::REGTEST;
    // !SCASH
    } else if (chain == "poolpay") {
        return ChainType::POOLPAYMAIN;
    } else if (chain == "poolpaytestnet") {
        return ChainType::POOLPAYTESTNET;
    } else if (chain == "poolpayregtest") {
        return ChainType::POOLPAYREGTEST;
    // !SCASH END
    } else {
        return std::nullopt;
    }
}
