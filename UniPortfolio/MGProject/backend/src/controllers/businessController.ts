import { Review } from './../database/entity/Review'
import { Business } from './../database/entity/Business'
import { getRepository } from 'typeorm' // allows us access to the connection object even though we are in a different file
import { OpeningTimes } from '../database/entity/OpeningTimes'
import { LocationMarker } from './../database/entity/LocationMarker'
import { BusinessImage } from '../database/entity/BusinessImage'

// * methods for testing
async function getAllBusinesses(req, res) {
    res.status(200).json(
        await getRepository(Business)
            .createQueryBuilder('business')
            .leftJoinAndSelect('business.openingTimes', 'openingTimes')
            .leftJoinAndSelect('business.locationMarker', 'locationMarker')
            .leftJoinAndSelect('business.reviews', 'reviews')
            .leftJoinAndSelect('business.images', 'images')
            .getMany(),
    )
}

async function getAllBusinessImages(req, res) {
    res.json(await getRepository(BusinessImage).find())
}

async function getAllOpeningTimes(req, res) {
    res.json(
        await getRepository(OpeningTimes)
            .createQueryBuilder('openingTimes')
            .getMany(),
    )
}

//* methods used by the frontend app:
async function getBusinessById(req, res) {
    res.status(200).json(
        await getRepository(Business)
            .createQueryBuilder('business')
            .leftJoinAndSelect('business.openingTimes', 'openingTimes')
            .leftJoinAndSelect('business.locationMarker', 'locationMarker')
            .leftJoinAndSelect('business.reviews', 'reviews')
            .leftJoinAndSelect('reviews.user', 'user')
            .leftJoinAndSelect('business.images', 'images')
            .where('business.id = :id', { id: req.params.id })
            .getOne(),
    )
}

async function addNewBusiness(req, res) {
    const businessDataFromClient = req.body
    // create a new OpeningTimes object
    let openingTimes = new OpeningTimes()
    openingTimes.monStartTime = businessDataFromClient.monday.start
    openingTimes.monEndTime = businessDataFromClient.monday.end
    openingTimes.tueStartTime = businessDataFromClient.tuesday.start
    openingTimes.tueEndTime = businessDataFromClient.tuesday.end
    openingTimes.wedStartTime = businessDataFromClient.wednesday.start
    openingTimes.wedEndTime = businessDataFromClient.wednesday.end
    openingTimes.thursStartTime = businessDataFromClient.thursday.start
    openingTimes.thursEndTime = businessDataFromClient.thursday.end
    openingTimes.friStartTime = businessDataFromClient.friday.start
    openingTimes.friEndTime = businessDataFromClient.friday.end
    openingTimes.satStartTime = businessDataFromClient.saturday.start
    openingTimes.satEndTime = businessDataFromClient.saturday.end
    openingTimes.sunStartTime = businessDataFromClient.sunday.start
    openingTimes.sunEndTime = businessDataFromClient.sunday.end
    await getRepository(OpeningTimes).save(openingTimes)

    // save all of the images to the database
    let images = []
    for (let image of businessDataFromClient.images) {
        let newImage = new BusinessImage()
        newImage.image = image
        await getRepository(BusinessImage).save(newImage)
        images.push(newImage)
    }

    // set up the Business object
    let business = new Business()
    business.name = businessDataFromClient.name
    business.url = businessDataFromClient.url
    business.averageRating = 0
    business.images = images
    business.openingTimes = openingTimes
    business.reviews = []
    await getRepository(Business).save(business)

    // set up the LocationMarker Object
    let locationMarker = new LocationMarker()
    locationMarker.longitude = businessDataFromClient.location.lng
    locationMarker.latitude = businessDataFromClient.location.lat
    locationMarker.business = business
    await getRepository(LocationMarker).save(locationMarker)

    res.status(201).send(`Saving ${req.body.name} to the database...`)
}

export default {
    getAllBusinesses,
    addNewBusiness,
    getAllOpeningTimes,
    getAllBusinessImages,
    getBusinessById,
}
