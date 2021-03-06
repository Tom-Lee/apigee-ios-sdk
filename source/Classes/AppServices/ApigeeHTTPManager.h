#import <Foundation/Foundation.h>

enum
{
    kApigeeHTTPGet = 0,
    kApigeeHTTPPost = 1,
    kApigeeHTTPPostAuth = 2,
    kApigeeHTTPPut = 3,
    kApigeeHTTPDelete = 4
};

@class ApigeeHTTPResult;
@class ApigeeHTTPManager;

typedef void (^ApigeeHTTPCompletionHandler)(ApigeeHTTPResult *result,ApigeeHTTPManager *httpManager);


@interface ApigeeHTTPManager : NSObject

// blocks until a response is received, or until there's an error.
// in the event of a response, it's returned. If there's an error, 
// the funciton returns nil and you can call getLastError to see what
// went wrong.
-(NSString *)syncTransaction:(NSString *)url operation:(int)op operationData:(NSString *)opData;

// sets up the transaction asynchronously. The delegate that's sent in
// must have the following functions: 
//
// -(void)httpManagerError:(ApigeeHTTPManager *)manager error:(NSString *)error
// -(void)httpManagerResponse:(ApigeeHTTPManager *)manager response:(NSString *)response
//
// In all cases, it returns a transaction ID. A return value
// of -1 means there was an error.
// You can call getLastError to find out what went wrong. 
-(int)asyncTransaction:(NSString *)url operation:(int)op operationData:(NSString *)opData delegate:(id)delegate;

-(int)asyncTransaction:(NSString *)url operation:(int)op operationData:(NSString *)opData completionHandler:(ApigeeHTTPCompletionHandler) completionHandler;

// get the current transactionID
-(int)getTransactionID;

// sets the auth key
-(void)setAuth: (NSString *)auth;

// cancel a pending transaction. The delegate will not be called and the results
// will be ignored. Though the server side will still have happened.
-(void)cancel;

// returns YES if this instance is available. NO if this instance is currently
// in use as part of an asynchronous transaction.
-(BOOL)isAvailable;

// sets the availability flag of this instance. This is done by ApigeeClient
-(void)setAvailable:(BOOL)available;

// a helpful utility function to make a string comform to URL
// rules. It will escape all the special characters.
+(NSString *)escapeSpecials:(NSString *)raw;

// At all times, this will return the plain-text explanation of the last
// thing that went wrong. It is cleared to "No Error" at the beginnign of 
// each new transaction.
-(NSString *)getLastError;

@end
