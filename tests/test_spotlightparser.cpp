/*
 * Copyright (c) 2018, Aetf <aetf at unlimitedcodeworks dot xyz>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright notice,
 *       this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright notice,
 *       this list of conditions and the following disclaimer in the documentation
 *       and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER
 * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "catch2_qt.h"
#include "spotlightprovider.h"

#include <catch2/catch.hpp>

#include <QDate>
#include <QUrl>

const auto exampleReply = QByteArrayLiteral(R"json(
{
  "batchrsp": {
    "ver": "1.0",
    "items": [
      {
        "item": "{\"f\":\"raf\",\"v\":\"1.0\",\"rdr\":[{\"c\":\"CDM\",\"u\":\"LockScreenHotSpots\"}],\"ad\":{\"image_fullscreen_001_landscape\":{\"t\":\"img\",\"w\":\"1920\",\"h\":\"1080\",\"u\":\"https://img-prod-cms-rt-microsoft-com.akamaized.net/cms/api/am/imageFileData/RE1LB8P?ver=24b9\",\"sha256\":\"zaUls2nxC2gB8vC7rqDieKx4DWSOgq/jli4Vx1tTE/0=\",\"fileSize\":\"1052948\"},\"image_fullscreen_001_portrait\":{\"t\":\"img\",\"w\":\"1080\",\"h\":\"1920\",\"u\":\"https://img-prod-cms-rt-microsoft-com.akamaized.net/cms/api/am/imageFileData/RE1LB8Q?ver=debd\",\"sha256\":\"S6EOBtWE6nh67X6uRMGbJH5RkgrxBEXRaC8S2RGCP6g=\",\"fileSize\":\"816060\"},\"hs1_title_text\":{\"t\":\"txt\",\"tx\":\"A refuge for sea turtles, a sanctuary for birds, and more than enough places…\"},\"hs1_icon\":{\"t\":\"txt\",\"tx\":\"\"},\"hs1_cta_text\":{\"t\":\"txt\",\"tx\":\"To keep shutterbugs happy\"},\"hs1_destination_url\":{\"t\":\"url\",\"u\":\"microsoft-edge:https://www.bing.com/images/search?q=Nusa+Penida+scenery&FORM=EMSDS0\"},\"hs1_x_coordinate_001_landscape\":{\"t\":\"txt\",\"tx\":\"72\"},\"hs1_y_coordinate_001_landscape\":{\"t\":\"txt\",\"tx\":\"72\"},\"hs1_x_coordinate_001_portrait\":{\"t\":\"txt\",\"tx\":\"72\"},\"hs1_y_coordinate_001_portrait\":{\"t\":\"txt\",\"tx\":\"72\"},\"hs2_title_text\":{\"t\":\"txt\",\"tx\":\"Don’t let the name fool you.\"},\"hs2_icon\":{\"t\":\"txt\",\"tx\":\"\"},\"hs2_cta_text\":{\"t\":\"txt\",\"tx\":\"The islands in this chain are pretty great\"},\"hs2_destination_url\":{\"t\":\"url\",\"u\":\"microsoft-edge:https://www.bing.com/search?q=Lesser+Sunda+Islands&filters=IsConversation%3a%22True%22+BTEPKey:%22Encyclo_WL_MantaBayNusaPenidaIslandBali%22&FORM=EMSDS0\"},\"hs2_x_coordinate_001_landscape\":{\"t\":\"txt\",\"tx\":\"850\"},\"hs2_y_coordinate_001_landscape\":{\"t\":\"txt\",\"tx\":\"550\"},\"hs2_x_coordinate_001_portrait\":{\"t\":\"txt\",\"tx\":\"380\"},\"hs2_y_coordinate_001_portrait\":{\"t\":\"txt\",\"tx\":\"750\"},\"title_text\":{\"t\":\"txt\",\"tx\":\"Nusa Penida Island\"},\"copyright_text\":{\"t\":\"txt\",\"tx\":\"© miniloc / iStock / Getty Images Plus\"},\"title_destination_url\":{\"t\":\"url\",\"u\":\"microsoft-edge:https://www.bing.com/search?q=Lesser+Sunda+Islands&filters=IsConversation%3a%22True%22+BTEPKey:%22Encyclo_WL_MantaBayNusaPenidaIslandBali%22&FORM=EMSDS0\"},\"tr_hint_hs1_1\":{\"t\":\"url\",\"u\":\"https://ris.api.iris.microsoft.com/v1/a/hover?CID=128000000000460982&region=US&lang=EN-US&oem=&devFam=&ossku=&cmdVer=&mo=&cap=&EID={EID}&&PID=425036077&UIT=M&TargetID=700260134&AN=770167789&PG=PC000P0FR5.0000000IRS&REQASID=5EBCF95FA2CD4644A32C2E77CA77FEEF&UNID=209567&ID=00000000000000000000000000000001&ANID=&MUID=&ASID={ASID}&PERSID=&AUID=&GlobalDeviceId=&LOCALID=&REQT=20180726T203126&TIME={DATETIME}&itemindex=1&bSrc=i.m\"},\"tr_click_hs1_1\":{\"t\":\"url\",\"u\":\"https://ris.api.iris.microsoft.com/v1/a/click?CID=128000000000460982&region=US&lang=EN-US&oem=&devFam=&ossku=&cmdVer=&mo=&cap=&EID={EID}&&PID=425036077&UIT=M&TargetID=700260134&AN=770167789&PG=PC000P0FR5.0000000IRS&REQASID=5EBCF95FA2CD4644A32C2E77CA77FEEF&UNID=209567&ID=00000000000000000000000000000001&ANID=&MUID=&ASID={ASID}&PERSID=&AUID=&GlobalDeviceId=&LOCALID=&REQT=20180726T203126&TIME={DATETIME}&itemindex=2&bSrc=i.m\"},\"tr_hint_hs2_1\":{\"t\":\"url\",\"u\":\"https://ris.api.iris.microsoft.com/v1/a/hover?CID=128000000000460982&region=US&lang=EN-US&oem=&devFam=&ossku=&cmdVer=&mo=&cap=&EID={EID}&&PID=425036077&UIT=M&TargetID=700260134&AN=770167789&PG=PC000P0FR5.0000000IRS&REQASID=5EBCF95FA2CD4644A32C2E77CA77FEEF&UNID=209567&ID=00000000000000000000000000000001&ANID=&MUID=&ASID={ASID}&PERSID=&AUID=&GlobalDeviceId=&LOCALID=&REQT=20180726T203126&TIME={DATETIME}&itemindex=3&bSrc=i.m\"},\"tr_click_hs2_1\":{\"t\":\"url\",\"u\":\"https://ris.api.iris.microsoft.com/v1/a/click?CID=128000000000460982&region=US&lang=EN-US&oem=&devFam=&ossku=&cmdVer=&mo=&cap=&EID={EID}&&PID=425036077&UIT=M&TargetID=700260134&AN=770167789&PG=PC000P0FR5.0000000IRS&REQASID=5EBCF95FA2CD4644A32C2E77CA77FEEF&UNID=209567&ID=00000000000000000000000000000001&ANID=&MUID=&ASID={ASID}&PERSID=&AUID=&GlobalDeviceId=&LOCALID=&REQT=20180726T203126&TIME={DATETIME}&itemindex=4&bSrc=i.m\"},\"tr_hint_hs3_1\":{\"t\":\"url\",\"u\":\"https://ris.api.iris.microsoft.com/v1/a/hover?CID=128000000000460982&region=US&lang=EN-US&oem=&devFam=&ossku=&cmdVer=&mo=&cap=&EID={EID}&&PID=425036077&UIT=M&TargetID=700260134&AN=770167789&PG=PC000P0FR5.0000000IRS&REQASID=5EBCF95FA2CD4644A32C2E77CA77FEEF&UNID=209567&ID=00000000000000000000000000000001&ANID=&MUID=&ASID={ASID}&PERSID=&AUID=&GlobalDeviceId=&LOCALID=&REQT=20180726T203126&TIME={DATETIME}&itemindex=5&bSrc=i.m\"},\"tr_click_hs3_1\":{\"t\":\"url\",\"u\":\"https://ris.api.iris.microsoft.com/v1/a/click?CID=128000000000460982&region=US&lang=EN-US&oem=&devFam=&ossku=&cmdVer=&mo=&cap=&EID={EID}&&PID=425036077&UIT=M&TargetID=700260134&AN=770167789&PG=PC000P0FR5.0000000IRS&REQASID=5EBCF95FA2CD4644A32C2E77CA77FEEF&UNID=209567&ID=00000000000000000000000000000001&ANID=&MUID=&ASID={ASID}&PERSID=&AUID=&GlobalDeviceId=&LOCALID=&REQT=20180726T203126&TIME={DATETIME}&itemindex=6&bSrc=i.m\"},\"tr_click_title_1\":{\"t\":\"url\",\"u\":\"https://ris.api.iris.microsoft.com/v1/a/click?CID=128000000000460982&region=US&lang=EN-US&oem=&devFam=&ossku=&cmdVer=&mo=&cap=&EID={EID}&&PID=425036077&UIT=M&TargetID=700260134&AN=770167789&PG=PC000P0FR5.0000000IRS&REQASID=5EBCF95FA2CD4644A32C2E77CA77FEEF&UNID=209567&ID=00000000000000000000000000000001&ANID=&MUID=&ASID={ASID}&PERSID=&AUID=&GlobalDeviceId=&LOCALID=&REQT=20180726T203126&TIME={DATETIME}&itemindex=7&bSrc=i.m\"}},\"prm\":{\"_id\":\"WW_128000000000460982_EN-US\",\"eid\":{\"t\":\"txt\",\"tx\":\"128000000000460982\"},\"expand_hotspots\":0,\"expireTime\":\"2035-12-31T07:59:00\",\"feedback_enabled\":1,\"hide_titles\":0,\"iaf_dislike\":{\"t\":\"url\",\"u\":\"https://ris.api.iris.microsoft.com/v1/a/dislike?CID=128000000000460982&region=US&lang=EN-US&oem=&devFam=&ossku=&cmdVer=&mo=&cap=&EID={EID}&&PID=425036077&UIT=M&TargetID=700260134&AN=770167789&PG=PC000P0FR5.0000000IRS&REQASID=5EBCF95FA2CD4644A32C2E77CA77FEEF&UNID=209567&ID=00000000000000000000000000000001&ANID=&MUID=&ASID={ASID}&PERSID=&AUID=&GlobalDeviceId=&LOCALID=&REQT=20180726T203126&TIME={DATETIME}&bSrc=i.f\"},\"iaf_impr\":{\"t\":\"url\",\"u\":\"https://ris.api.iris.microsoft.com/v1/a/iaf_impression?CID=128000000000460982&region=US&lang=EN-US&oem=&devFam=&ossku=&cmdVer=&mo=&cap=&EID={EID}&&PID=425036077&UIT=M&TargetID=700260134&AN=770167789&PG=PC000P0FR5.0000000IRS&REQASID=5EBCF95FA2CD4644A32C2E77CA77FEEF&UNID=209567&ID=00000000000000000000000000000001&ANID=&MUID=&ASID={ASID}&PERSID=&AUID=&GlobalDeviceId=&LOCALID=&REQT=20180726T203126&TIME={DATETIME}\"},\"iaf_like\":{\"t\":\"url\",\"u\":\"https://ris.api.iris.microsoft.com/v1/a/like?CID=128000000000460982&region=US&lang=EN-US&oem=&devFam=&ossku=&cmdVer=&mo=&cap=&EID={EID}&&PID=425036077&UIT=M&TargetID=700260134&AN=770167789&PG=PC000P0FR5.0000000IRS&REQASID=5EBCF95FA2CD4644A32C2E77CA77FEEF&UNID=209567&ID=00000000000000000000000000000001&ANID=&MUID=&ASID={ASID}&PERSID=&AUID=&GlobalDeviceId=&LOCALID=&REQT=20180726T203126&TIME={DATETIME}&bSrc=i.f\"},\"reuseCount\":-1,\"rotationPeriod\":82800,\"requiresNetwork\":0,\"startTime\":\"2018-05-09T22:24:00\",\"_imp\":\"post:https://arc.msn.com/v3/Delivery/Events/Impression=&PID=425036077&TID=700260134&CID=128000000000460982&BID=770167789&PG=PC000P0FR5.0000000IRS&TPID=425036077&REQASID=5EBCF95FA2CD4644A32C2E77CA77FEEF&ASID={ASID}&TIME={DATETIME}&SLOT=&REQT=20180726T203126&MA_Score=2&SegmentHash=&DS_Pids=&DS_PDFS=&DS_Result=&DS_Status=&DS_Index=&CNIMP=5&CNNA=2&CNMC=20&PG=PC000P0FR5.0000000G77&UNID=209567&MAP_TID=FE0A0A10-7F27-4C58-9894-F016481DB730&ASID=5EBCF95FA2CD4644A32C2E77CA77FEEF&REQASID=5EBCF95FA2CD4644A32C2E77CA77FEEF&ARC=1&EMS=1&LOCALE=EN_US&COUNTRY=US&HTD=-1&LANG=1033&DEVLANG=EN&CIP=141.212.110.119&OPTOUTSTATE=0&HTTPS=1&LOD=55&LOH=24&LO=80217&RAFB=0&MARKETBASEDCOUNTRY=US&CFMT=&SFT=GIF%2CAGIF%2CJPEG%2CJPG%2CBMP%2CPNG&H=320&W=240&FESVER=1.3&DISPHORZRES=9999&DISPVERTRES=9999&PL=EN-US&TIME=2017-12-31T23%3A59%3A59Z&CHNL=CFD\"}}"
      }
    ],
    "itemorder": [
      0
    ],
    "refreshtime": "2018-08-02T20:31:26"
  }
}
)json");

const auto exampleImageItem = QStringLiteral(
    R"json({"f":"raf","v":"1.0","rdr":[{"c":"CDM","u":"LockScreenHotSpots"}],"ad":{"image_fullscreen_001_landscape":{"t":"img","w":"1920","h":"1080","u":"https://img-prod-cms-rt-microsoft-com.akamaized.net/cms/api/am/imageFileData/RE1LB8P?ver=24b9","sha256":"zaUls2nxC2gB8vC7rqDieKx4DWSOgq/jli4Vx1tTE/0=","fileSize":"1052948"},"image_fullscreen_001_portrait":{"t":"img","w":"1080","h":"1920","u":"https://img-prod-cms-rt-microsoft-com.akamaized.net/cms/api/am/imageFileData/RE1LB8Q?ver=debd","sha256":"S6EOBtWE6nh67X6uRMGbJH5RkgrxBEXRaC8S2RGCP6g=","fileSize":"816060"},"hs1_title_text":{"t":"txt","tx":"A refuge for sea turtles, a sanctuary for birds, and more than enough places…"},"hs1_icon":{"t":"txt","tx":""},"hs1_cta_text":{"t":"txt","tx":"To keep shutterbugs happy"},"hs1_destination_url":{"t":"url","u":"microsoft-edge:https://www.bing.com/images/search?q=Nusa+Penida+scenery&FORM=EMSDS0"},"hs1_x_coordinate_001_landscape":{"t":"txt","tx":"72"},"hs1_y_coordinate_001_landscape":{"t":"txt","tx":"72"},"hs1_x_coordinate_001_portrait":{"t":"txt","tx":"72"},"hs1_y_coordinate_001_portrait":{"t":"txt","tx":"72"},"hs2_title_text":{"t":"txt","tx":"Don’t let the name fool you."},"hs2_icon":{"t":"txt","tx":""},"hs2_cta_text":{"t":"txt","tx":"The islands in this chain are pretty great"},"hs2_destination_url":{"t":"url","u":"microsoft-edge:https://www.bing.com/search?q=Lesser+Sunda+Islands&filters=IsConversation%3a%22True%22+BTEPKey:%22Encyclo_WL_MantaBayNusaPenidaIslandBali%22&FORM=EMSDS0"},"hs2_x_coordinate_001_landscape":{"t":"txt","tx":"850"},"hs2_y_coordinate_001_landscape":{"t":"txt","tx":"550"},"hs2_x_coordinate_001_portrait":{"t":"txt","tx":"380"},"hs2_y_coordinate_001_portrait":{"t":"txt","tx":"750"},"title_text":{"t":"txt","tx":"Nusa Penida Island"},"copyright_text":{"t":"txt","tx":"© miniloc / iStock / Getty Images Plus"},"title_destination_url":{"t":"url","u":"microsoft-edge:https://www.bing.com/search?q=Lesser+Sunda+Islands&filters=IsConversation%3a%22True%22+BTEPKey:%22Encyclo_WL_MantaBayNusaPenidaIslandBali%22&FORM=EMSDS0"},"tr_hint_hs1_1":{"t":"url","u":"https://ris.api.iris.microsoft.com/v1/a/hover?CID=128000000000460982&region=US&lang=EN-US&oem=&devFam=&ossku=&cmdVer=&mo=&cap=&EID={EID}&&PID=425036077&UIT=M&TargetID=700260134&AN=770167789&PG=PC000P0FR5.0000000IRS&REQASID=5EBCF95FA2CD4644A32C2E77CA77FEEF&UNID=209567&ID=00000000000000000000000000000001&ANID=&MUID=&ASID={ASID}&PERSID=&AUID=&GlobalDeviceId=&LOCALID=&REQT=20180726T203126&TIME={DATETIME}&itemindex=1&bSrc=i.m"},"tr_click_hs1_1":{"t":"url","u":"https://ris.api.iris.microsoft.com/v1/a/click?CID=128000000000460982&region=US&lang=EN-US&oem=&devFam=&ossku=&cmdVer=&mo=&cap=&EID={EID}&&PID=425036077&UIT=M&TargetID=700260134&AN=770167789&PG=PC000P0FR5.0000000IRS&REQASID=5EBCF95FA2CD4644A32C2E77CA77FEEF&UNID=209567&ID=00000000000000000000000000000001&ANID=&MUID=&ASID={ASID}&PERSID=&AUID=&GlobalDeviceId=&LOCALID=&REQT=20180726T203126&TIME={DATETIME}&itemindex=2&bSrc=i.m"},"tr_hint_hs2_1":{"t":"url","u":"https://ris.api.iris.microsoft.com/v1/a/hover?CID=128000000000460982&region=US&lang=EN-US&oem=&devFam=&ossku=&cmdVer=&mo=&cap=&EID={EID}&&PID=425036077&UIT=M&TargetID=700260134&AN=770167789&PG=PC000P0FR5.0000000IRS&REQASID=5EBCF95FA2CD4644A32C2E77CA77FEEF&UNID=209567&ID=00000000000000000000000000000001&ANID=&MUID=&ASID={ASID}&PERSID=&AUID=&GlobalDeviceId=&LOCALID=&REQT=20180726T203126&TIME={DATETIME}&itemindex=3&bSrc=i.m"},"tr_click_hs2_1":{"t":"url","u":"https://ris.api.iris.microsoft.com/v1/a/click?CID=128000000000460982&region=US&lang=EN-US&oem=&devFam=&ossku=&cmdVer=&mo=&cap=&EID={EID}&&PID=425036077&UIT=M&TargetID=700260134&AN=770167789&PG=PC000P0FR5.0000000IRS&REQASID=5EBCF95FA2CD4644A32C2E77CA77FEEF&UNID=209567&ID=00000000000000000000000000000001&ANID=&MUID=&ASID={ASID}&PERSID=&AUID=&GlobalDeviceId=&LOCALID=&REQT=20180726T203126&TIME={DATETIME}&itemindex=4&bSrc=i.m"},"tr_hint_hs3_1":{"t":"url","u":"https://ris.api.iris.microsoft.com/v1/a/hover?CID=128000000000460982&region=US&lang=EN-US&oem=&devFam=&ossku=&cmdVer=&mo=&cap=&EID={EID}&&PID=425036077&UIT=M&TargetID=700260134&AN=770167789&PG=PC000P0FR5.0000000IRS&REQASID=5EBCF95FA2CD4644A32C2E77CA77FEEF&UNID=209567&ID=00000000000000000000000000000001&ANID=&MUID=&ASID={ASID}&PERSID=&AUID=&GlobalDeviceId=&LOCALID=&REQT=20180726T203126&TIME={DATETIME}&itemindex=5&bSrc=i.m"},"tr_click_hs3_1":{"t":"url","u":"https://ris.api.iris.microsoft.com/v1/a/click?CID=128000000000460982&region=US&lang=EN-US&oem=&devFam=&ossku=&cmdVer=&mo=&cap=&EID={EID}&&PID=425036077&UIT=M&TargetID=700260134&AN=770167789&PG=PC000P0FR5.0000000IRS&REQASID=5EBCF95FA2CD4644A32C2E77CA77FEEF&UNID=209567&ID=00000000000000000000000000000001&ANID=&MUID=&ASID={ASID}&PERSID=&AUID=&GlobalDeviceId=&LOCALID=&REQT=20180726T203126&TIME={DATETIME}&itemindex=6&bSrc=i.m"},"tr_click_title_1":{"t":"url","u":"https://ris.api.iris.microsoft.com/v1/a/click?CID=128000000000460982&region=US&lang=EN-US&oem=&devFam=&ossku=&cmdVer=&mo=&cap=&EID={EID}&&PID=425036077&UIT=M&TargetID=700260134&AN=770167789&PG=PC000P0FR5.0000000IRS&REQASID=5EBCF95FA2CD4644A32C2E77CA77FEEF&UNID=209567&ID=00000000000000000000000000000001&ANID=&MUID=&ASID={ASID}&PERSID=&AUID=&GlobalDeviceId=&LOCALID=&REQT=20180726T203126&TIME={DATETIME}&itemindex=7&bSrc=i.m"}},"prm":{"_id":"WW_128000000000460982_EN-US","eid":{"t":"txt","tx":"128000000000460982"},"expand_hotspots":0,"expireTime":"2035-12-31T07:59:00","feedback_enabled":1,"hide_titles":0,"iaf_dislike":{"t":"url","u":"https://ris.api.iris.microsoft.com/v1/a/dislike?CID=128000000000460982&region=US&lang=EN-US&oem=&devFam=&ossku=&cmdVer=&mo=&cap=&EID={EID}&&PID=425036077&UIT=M&TargetID=700260134&AN=770167789&PG=PC000P0FR5.0000000IRS&REQASID=5EBCF95FA2CD4644A32C2E77CA77FEEF&UNID=209567&ID=00000000000000000000000000000001&ANID=&MUID=&ASID={ASID}&PERSID=&AUID=&GlobalDeviceId=&LOCALID=&REQT=20180726T203126&TIME={DATETIME}&bSrc=i.f"},"iaf_impr":{"t":"url","u":"https://ris.api.iris.microsoft.com/v1/a/iaf_impression?CID=128000000000460982&region=US&lang=EN-US&oem=&devFam=&ossku=&cmdVer=&mo=&cap=&EID={EID}&&PID=425036077&UIT=M&TargetID=700260134&AN=770167789&PG=PC000P0FR5.0000000IRS&REQASID=5EBCF95FA2CD4644A32C2E77CA77FEEF&UNID=209567&ID=00000000000000000000000000000001&ANID=&MUID=&ASID={ASID}&PERSID=&AUID=&GlobalDeviceId=&LOCALID=&REQT=20180726T203126&TIME={DATETIME}"},"iaf_like":{"t":"url","u":"https://ris.api.iris.microsoft.com/v1/a/like?CID=128000000000460982&region=US&lang=EN-US&oem=&devFam=&ossku=&cmdVer=&mo=&cap=&EID={EID}&&PID=425036077&UIT=M&TargetID=700260134&AN=770167789&PG=PC000P0FR5.0000000IRS&REQASID=5EBCF95FA2CD4644A32C2E77CA77FEEF&UNID=209567&ID=00000000000000000000000000000001&ANID=&MUID=&ASID={ASID}&PERSID=&AUID=&GlobalDeviceId=&LOCALID=&REQT=20180726T203126&TIME={DATETIME}&bSrc=i.f"},"reuseCount":-1,"rotationPeriod":82800,"requiresNetwork":0,"startTime":"2018-05-09T22:24:00","_imp":"post:https://arc.msn.com/v3/Delivery/Events/Impression=&PID=425036077&TID=700260134&CID=128000000000460982&BID=770167789&PG=PC000P0FR5.0000000IRS&TPID=425036077&REQASID=5EBCF95FA2CD4644A32C2E77CA77FEEF&ASID={ASID}&TIME={DATETIME}&SLOT=&REQT=20180726T203126&MA_Score=2&SegmentHash=&DS_Pids=&DS_PDFS=&DS_Result=&DS_Status=&DS_Index=&CNIMP=5&CNNA=2&CNMC=20&PG=PC000P0FR5.0000000G77&UNID=209567&MAP_TID=FE0A0A10-7F27-4C58-9894-F016481DB730&ASID=5EBCF95FA2CD4644A32C2E77CA77FEEF&REQASID=5EBCF95FA2CD4644A32C2E77CA77FEEF&ARC=1&EMS=1&LOCALE=EN_US&COUNTRY=US&HTD=-1&LANG=1033&DEVLANG=EN&CIP=141.212.110.119&OPTOUTSTATE=0&HTTPS=1&LOD=55&LOH=24&LO=80217&RAFB=0&MARKETBASEDCOUNTRY=US&CFMT=&SFT=GIF%2CAGIF%2CJPEG%2CJPG%2CBMP%2CPNG&H=320&W=240&FESVER=1.3&DISPHORZRES=9999&DISPVERTRES=9999&PL=EN-US&TIME=2017-12-31T23%3A59%3A59Z&CHNL=CFD"}})json");

TEST_CASE("SpotlightParser can form or decode the Spotlight API", "[spotlight]")
{
    SECTION("Country letters from locale are in lower case")
    {
        QLocale en_US("en_US");
        REQUIRE(SpotlightParser::getCountryLetters(en_US) == "us");

        QLocale zh_CN("zh_CN");
        REQUIRE(SpotlightParser::getCountryLetters(zh_CN) == "cn");

        QLocale de_CH("de_CH");
        REQUIRE(SpotlightParser::getCountryLetters(de_CH) == "ch");
    }

    SECTION("Valid URL can be built")
    {
        const QUrl exampleUrl("https://arc.msn.com/v3/Delivery/Cache?"
                              "pid=209567&fmt=json&disphorzres=9999&dispvertres=9999"
                              "&pl=en-US&lc=en-US&ctry=us&time=2017-12-31T23:59:59Z");
        const QDateTime exampleDt = QDateTime::fromString("2017-12-31T23:59:59Z", Qt::ISODate);
        const QLocale exampleLocale("en_US");

        REQUIRE(SpotlightParser::buildUrl(exampleDt, exampleLocale) == exampleUrl);

        REQUIRE(SpotlightParser::buildUrl(QDateTime::currentDateTime()).isValid());
    }

    SECTION("Image item can be extracted from reply")
    {
        const auto imageItem = SpotlightParser::parseReply(exampleReply);

        // REQUIRE(imageItem.size() == exampleImageItem.size());
        REQUIRE(imageItem == exampleImageItem);

        SECTION("Image url can be extracted from the item string")
        {
            const auto imageUrl = SpotlightParser::extractImageUrl(imageItem);

            REQUIRE(imageUrl
                    == QUrl("https://img-prod-cms-rt-microsoft-com.akamaized.net/cms/api/am/imageFileData/"
                            "RE1LB8P?ver=24b9"));
        }
    }
}
