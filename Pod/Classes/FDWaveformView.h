//
//  FDWaveformView
//
//  Created by William Entriken on 10/6/13.
//  Copyright (c) 2013 William Entriken. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MediaPlayer/MediaPlayer.h>
#import <AVFoundation/AVFoundation.h>

@protocol FDWaveformViewDelegate;

@interface FDWaveformView : UIView
@property (nonatomic, weak) id<FDWaveformViewDelegate> delegate;
@property (nonatomic, strong) NSURL *audioURL;
@property (nonatomic, assign, readonly) long int totalSamples;
@property (nonatomic, assign) long int progressSamples;
@property (nonatomic, assign) long int zoomStartSamples;
@property (nonatomic, assign) long int zoomEndSamples;
@property (nonatomic) BOOL doesAllowScrubbing;
@property (nonatomic) BOOL doesAllowStretch;
@property (nonatomic) BOOL doesAllowScroll;
@property (nonatomic, copy) UIColor *wavesColor;
@property (nonatomic, copy) UIColor *progressColor;

- (void)setAudioURL:(NSURL *)audioURL zoomStartSamples:(long int)zoomStartSamples zoomEndSamples:(long int)zoomEndSamples;

@end

@protocol FDWaveformViewDelegate <NSObject>
@optional
- (void)waveformViewWillRender:(FDWaveformView *)waveformView;
- (void)waveformViewDidRender:(FDWaveformView *)waveformView;
- (void)waveformViewWillLoad:(FDWaveformView *)waveformView;
- (void)waveformViewDidLoad:(FDWaveformView *)waveformView;
- (void)waveformDidBeginPanning:(FDWaveformView *)waveformView;
- (void)waveformDidEndPanning:(FDWaveformView *)waveformView;
@end