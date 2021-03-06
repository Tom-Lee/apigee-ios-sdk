//
//  ApigeeNetworkEntry.h
//  ApigeeAppMonitor
//
//  Copyright (c) 2012 Apigee. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ApigeeNetworkEntry : NSObject

@property (strong) NSString *url;
@property (strong) NSString *timeStamp;
@property (strong) NSString *startTime;
@property (strong) NSString *endTime;
@property (strong) NSString *latency;
@property (strong) NSString *numSamples;
@property (strong) NSString *numErrors;
@property (strong) NSString *transactionDetails;
@property (strong) NSString *httpStatusCode;
@property (strong) NSString *responseDataSize;
@property (strong) NSString *serverProcessingTime;
@property (strong) NSString *serverReceiptTime;
@property (strong) NSString *serverResponseTime;
@property (strong) NSString *serverId;
@property (strong) NSString *domain;
//@property (strong) NSNumber *allowsCellularAccess;

- (id)init;

- (NSDictionary*) asDictionary;

- (void)populateWithURLString:(NSString*)urlString;
- (void)populateWithURL:(NSURL*)theUrl;
- (void)populateWithRequest:(NSURLRequest*)request;
- (void)populateWithResponse:(NSURLResponse*)response;
- (void)populateWithResponseData:(NSData*)responseData;
- (void)populateWithError:(NSError*)error;
- (void)populateStartTime:(NSDate*)started ended:(NSDate*)ended;

@end
