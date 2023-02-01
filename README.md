# QtProj

coordinate transformation tool by proj4 and Qt

## Depends

* [proj](https://proj.org/)

## Example

### SRC

```
+proj=tmerc +lat_0=0 +lon_0=39 +k=1 +x_0=134156.988 +y_0=-6032524.376 +ellps=krass +towgs84=24.83,-130.97,-81.74,0,0,-0.13,-0.22 +units=m +no_defs
190473.82
229747.11
0
```

### DEST

```
+proj=longlat



```

### Result

```
+proj=longlat
56.11910749
40.53684436
0.00000000
```
