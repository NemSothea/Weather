//
//  RSLocalPageController.h
//  Weather
//
//  Created by Eugene Scherba on 11/7/12.
//
//

#import <UIKit/UIKit.h>
#import "WeatherForecast.h"
#import "RSAddGeo.h"
#import "FindNearbyPlace.h"
#import "PullToRefreshView.h"

@interface RSLocalPageController : UIViewController <UITableViewDelegate, UITableViewDataSource, WeatherForecastDelegate, PullToRefreshViewDelegate> {

    WeatherAppDelegate *appDelegate;
    NSDictionary *wsymbols;
    
    IBOutlet UIActivityIndicatorView *loadingActivityIndicator;
    
    // different location (in different time zones) could have different dates
    NSDateFormatter *timeFormatter;
    NSDateFormatter *weekdayFormatter;
    BOOL showingImperial;
    NSInteger sunPosition;
    
    NSCalendar *localCalendar;
    
    IBOutlet UIImageView *nowImage;
    IBOutlet UILabel *nameLabel;
    IBOutlet UILabel *nowTempLabel;
    IBOutlet UILabel *nowHumidityLabel;
    IBOutlet UILabel *nowWindLabel;
    IBOutlet UILabel *nowConditionLabel;
    IBOutlet UILabel *nowTimeLabel;
    
    PullToRefreshView *pull;
    IBOutlet UITableView *_tableView;
}

-(void)viewMayNeedUpdate;
-(void)currentLocationDidUpdate:(CLLocation *)location;
-(void)findNearbyPlaceDidFinish;

@property (nonatomic, retain) UIActivityIndicatorView *loadingActivityIndicator;
@property (nonatomic, retain) WeatherForecast *forecast;
@property (nonatomic, assign) BOOL showingImperial;

// although locality is also retained by the model, we retain it here
// because we attach an observer onto it, and we want to keep it until dealloc
@property (nonatomic, retain) RSLocality* locality;

// debug
@property (nonatomic, assign) NSUInteger pageNumber;

@end
