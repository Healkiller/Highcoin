// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "assert.h"

#include "chainparams.h"
#include "main.h"
#include "util.h"

#include <boost/assign/list_of.hpp>

using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

//
// Main network
//

// Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress> &vSeedsOut, const SeedSpec6 *data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7*24*60*60;
    for (unsigned int i = 0; i < count; i++)
    {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

class CMainParams : public CChainParams {
public:
    CMainParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0xdf;
        pchMessageStart[1] = 0xc9;
        pchMessageStart[2] = 0xc5;
        pchMessageStart[3] = 0x7c;
        vAlertPubKey = ParseHex("01547afdb0fe5548271967f1a67130b7105cd6a828e03909a67962e0ea1f61deb649f6bc3f4cef38c4f35504e51ec112de5c384df7ba0b8d578a4c702b6bf11d5f");
        nDefaultPort = 10036;
        nRPCPort = 10034;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 20);
        bnProofOfStakeLimit = CBigNum(~uint256(0) >> 20);

        const char* pszTimestamp = "Highcoin 3.0";  
        std::vector<CTxIn> vin;
        vin.resize(1);
        vin[0].scriptSig = CScript() << 0 << CBigNum(42) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        std::vector<CTxOut> vout;
        vout.resize(1);
        vout[0].SetEmpty();
        CTransaction txNew(1, 1534864275, vin, vout, 0); // Saturday, 15-Oct-16 12:00:00 UTC 
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime    = 1534864275;
        genesis.nBits    = 0x1e0ffff0;
        genesis.nNonce   = 1665558;

/* genesis.nTime = 1534864275
genesis.nNonce = 1665558
genesis.nVersion = 1
genesis.GetHash = 00000e9e82e30754b9f6ad23ab8e8ee7abf53514d2f69ed2523e6fc23318e708
genesis.hashMerkleRoot = d6e1af9910bf1882a76c8bcc0ef255c6f24c74617dfbe873e7b02d625101b98e
*/















        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x00000e9e82e30754b9f6ad23ab8e8ee7abf53514d2f69ed2523e6fc23318e708"));
        assert(genesis.hashMerkleRoot == uint256("0xd6e1af9910bf1882a76c8bcc0ef255c6f24c74617dfbe873e7b02d625101b98e"));

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,100);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,110);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,50);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x88)(0xB2)(0x1E).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x88)(0xAD)(0xE4).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        nTargetSpacing = 10 * 60; // Initially 10min during PoW
        nTargetTimespan = 50 * 3 * 60;
        nLastPoWBlock = 1000000;
        nStartPoSBlock = 5000;
    }



    virtual const CBlock& GenesisBlock() const { return genesis; }
    virtual Network NetworkID() const { return CChainParams::MAIN; }

    virtual const vector<CAddress>& FixedSeeds() const {
        return vFixedSeeds;
    }
protected:
    CBlock genesis;
    vector<CAddress> vFixedSeeds;
};
static CMainParams mainParams;


//
// Testnet
//

class CTestNetParams : public CMainParams {
public:
    CTestNetParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0x12;
        pchMessageStart[1] = 0x1a;
        pchMessageStart[2] = 0x52;
        pchMessageStart[3] = 0xb4;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 16);
        bnProofOfStakeLimit = CBigNum(~uint256(0) >> 16);

        vAlertPubKey = ParseHex("06b54765b12e9056bc6b132a04b94acefeac5d5257fe028e80695c62f7c2f81f85d251a216df3af197653f454852a2d08c6314aad5ca3cbe5616262ca3e7a6feef");
        nDefaultPort = 10022;
        nRPCPort = 10028;
        strDataDir = "testnet";

        // Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nBits  = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce = 169332;


	/* 
	genesis.nTime = 1534864275
	genesis.nNonce = 169332
	genesis.nVersion = 1
	genesis.GetHash = 000047064111a93db30cc60ee8db906ce53a35bfec4b1c32079e79228c457666
	genesis.hashMerkleRoot = d6e1af9910bf1882a76c8bcc0ef255c6f24c74617dfbe873e7b02d625101b98e
	*/




        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x000047064111a93db30cc60ee8db906ce53a35bfec4b1c32079e79228c457666"));

        vFixedSeeds.clear();
        vSeeds.clear();

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,93);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,111);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,51);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x88)(0xB2)(0x1E).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x88)(0xAD)(0xE4).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));

        nTargetSpacing = 200;
        nLastPoWBlock = 0x7fffffff;
        nStartPoSBlock = 4500;
    }
    virtual Network NetworkID() const { return CChainParams::TESTNET; }
};
static CTestNetParams testNetParams;


//
// Regression test
//
class CRegTestParams : public CTestNetParams {
public:
    CRegTestParams() {
	pchMessageStart[0] = 0xdf;
        pchMessageStart[1] = 0xc9;
        pchMessageStart[2] = 0xc5;
        pchMessageStart[3] = 0x7c;

        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 1);
        genesis.nTime = 1534864275;
        genesis.nBits  = 0x1e0ffff0;
        genesis.nNonce = 1665558;
        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 19001;
        strDataDir = "regtest";


       

        assert(hashGenesisBlock == uint256("0x00000e9e82e30754b9f6ad23ab8e8ee7abf53514d2f69ed2523e6fc23318e708"));

        vSeeds.clear();  // Regtest mode doesn't have any DNS seeds.
    }

    virtual bool RequireRPCPassword() const { return false; }
    virtual Network NetworkID() const { return CChainParams::REGTEST; }
};
static CRegTestParams regTestParams;

static CChainParams *pCurrentParams = &mainParams;

const CChainParams &Params() {
    return *pCurrentParams;
}

void SelectParams(CChainParams::Network network) {
    switch (network) {
        case CChainParams::MAIN:
            pCurrentParams = &mainParams;
            break;
        case CChainParams::TESTNET:
            pCurrentParams = &testNetParams;
            break;
        case CChainParams::REGTEST:
            pCurrentParams = &regTestParams;
            break;
        default:
            assert(false && "Unimplemented network");
            return;
    }
}

bool SelectParamsFromCommandLine() {
    bool fRegTest = GetBoolArg("-regtest", false);
    bool fTestNet = GetBoolArg("-testnet", false);

    if (fTestNet && fRegTest) {
        return false;
    }

    if (fRegTest) {
        SelectParams(CChainParams::REGTEST);
    } else if (fTestNet) {
        SelectParams(CChainParams::TESTNET);
    } else {
        SelectParams(CChainParams::MAIN);
    }
    return true;
}
