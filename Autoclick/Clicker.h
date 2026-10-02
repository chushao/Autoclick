//
//  Clicker.h
//  Autoclick
//

#import <Foundation/Foundation.h>

@interface Clicker : NSObject {
    BOOL isClicking;
    BOOL isWaiting;
    BOOL fnPressed;
    
    NSTimer* waitingTimer;
    NSInteger stationarySeconds;
    NSTimeInterval lastMoved; // Mouse
    NSTextField* statusLabel;
    
    NSThread* clickThread;

    CGMouseButton clickButton;
    NSTimeInterval clickInterval; // seconds
    double clickJitter; // fraction of clickInterval, e.g. 0.2 = ±20%
    NSTimeInterval nextClickTime; // reference-date seconds, used when jittering
}

@property (assign) BOOL isClicking;

- (void)stopClicking;
- (void)startClicking:(int)button rate:(NSTimeInterval)rate jitter:(double)jitter
                startAfter:(NSInteger)start stopAfter:(NSInteger)stop
              ifStationaryFor:(NSInteger)stationary;

@end
